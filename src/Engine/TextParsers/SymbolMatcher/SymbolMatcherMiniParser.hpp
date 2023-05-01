#pragma once

#include "Utility/MiniParser.hpp"
#include "SymbolMatcher.hpp"

namespace MiniParser
{
	using SymbolMatcher::Symbol;
	using SymbolMatcher::SymbolMatch;

	template <class T>
	concept SymbolAction = requires (T&& callable, const Symbol& symbol, const std::string_view& value)
	{
		{ callable(symbol, value) } -> std::convertible_to<bool>;
	};

	template <class T>
	concept SymbolAndTailAction = requires (T&& callable, const Symbol& symbol, const std::string_view& value, const std::string_view& tail)
	{
		{ callable(symbol, value, tail) } -> std::convertible_to<bool>;
	};

	template <class T>
	concept SymbolMatchAction = requires (T&& callable, const SymbolMatch& match)
	{
		{ callable(match) } -> std::convertible_to<bool>;
	};

	template <class T>
	concept SymbolMatchAndTailAction = requires (T&& callable, const SymbolMatch& match, const std::string_view& tail)
	{
		{ callable(match, tail) } -> std::convertible_to<bool>;
	};

	template <class T>
	concept AllSymbolsAction = requires (T&& callable, const std::vector<SymbolMatch>& matches)
	{
		{ callable(matches) } -> std::convertible_to<bool>;
	};

	template <class T>
	concept AnySingleSymbolAction = SymbolAction<T> or SymbolAndTailAction<T> or SymbolMatchAction<T> or SymbolMatchAndTailAction<T>;

	template <class T>
	concept AnySymbolAction = AnySingleSymbolAction<T> or AllSymbolsAction<T>;

	template <typename T, typename ValueType>
	concept SymbolValueMap =
		std::is_same_v<T, std::map<Symbol, ValueType, typename T::key_compare, typename T::allocator_type>> or
		std::is_same_v<T, std::unordered_map<Symbol, ValueType, typename T::hasher, typename T::key_equal, typename T::allocator_type>>;

	namespace Detail
	{
		struct SymbolActionInvoker
		{
			template <SymbolAction Action>
			bool operator()(auto& s, const SymbolMatch& match, Action&& action) const
			{
				return action(match.symbol, match.value);
			}

			template <SymbolAndTailAction Action>
			bool operator()(auto& s, const SymbolMatch& match, Action&& action) const
			{
				return action(match.symbol, match.value, s.substr(match.value.length()));
			}

			template <SymbolMatchAction Action>
			bool operator()(auto& s, const SymbolMatch& match, Action&& action) const
			{
				return action(match);
			}

			template <SymbolMatchAndTailAction Action>
			bool operator()(auto& s, const SymbolMatch& match, Action&& action) const
			{
				return action(match, s.substr(match.value.length()));
			}

			template <AllSymbolsAction Action>
			bool operator()(auto& s, const std::vector<SymbolMatch>& matches, Action&& action) const
			{
				return action(matches);
			}
		};

		template <class ValueType, class MapType> requires SymbolValueMap<MapType, ValueType>
		inline bool TranslateSymbol(const Symbol& s, ValueType& value, const MapType& value_map, const ValueType& default_value)
		{
			auto it = value_map.find(s);
			if (it == value_map.end())
			{
				value = default_value;
				return false;
			}
			else
			{
				value = it->second;
				return true;
			}
		}
	}

	template <std::forward_iterator It, AnySingleSymbolAction SymAction, AnyParserAction... Actions>
	inline bool ParseTokenSymbol(It& it, SymAction&& symbol_action, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		auto match = SymbolMatcher::MatchSingleSymbol(token_view);
		return Detail::SymbolActionInvoker()(token_view, match, std::forward<SymAction&&>(symbol_action));
	}

	template <std::forward_iterator It, AnySingleSymbolAction SymAction, AnyParserAction... Actions>
	inline bool ParseTokenSymbol(It& it, SymbolMatch& match, SymAction&& symbol_action, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		match = SymbolMatcher::MatchSingleSymbol(token_view);
		return Detail::SymbolActionInvoker()(token_view, match, std::forward<SymAction&&>(symbol_action));
	}

	template <std::forward_iterator It, AllSymbolsAction SymAction, AnyParserAction... Actions>
	inline bool ParseTokenSymbols(It& it, SymAction&& symbols_action, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		auto matches = SymbolMatcher::MatchAllSymbols(token_view);
		return Detail::SymbolActionInvoker()(token_view, matches, std::forward<SymAction&&>(symbols_action));
	}

	template <std::forward_iterator It, AllSymbolsAction SymAction, AnyParserAction... Actions>
	inline bool ParseTokenSymbols(It& it, auto& matches, SymAction&& symbols_action, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		matches = SymbolMatcher::MatchAllSymbols(token_view);
		return Detail::SymbolActionInvoker()(token_view, matches, std::forward<SymAction&&>(symbols_action));
	}

	template <std::forward_iterator It, class ValueType, class ValueMap, AnyParserAction... Actions> requires SymbolValueMap<ValueMap, ValueType>
	inline bool ParseTokenSymbol(It& it, ValueType& value, const ValueMap& value_map, const ValueType& default_value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		auto match = SymbolMatcher::MatchSingleSymbol(token_view);
		return Detail::TranslateSymbol(match.symbol, value, value_map, default_value);
	}

	template <std::forward_iterator It, class ValueType, class ValueMap, AnyParserAction... Actions> requires SymbolValueMap<ValueMap, ValueType>
	inline bool ParseTokenSymbol(It& it, SymbolMatch& match, ValueType& value, const ValueMap& value_map, const ValueType& default_value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		match = SymbolMatcher::MatchSingleSymbol(token_view);
		return Detail::TranslateSymbol(match.symbol, value, value_map, default_value);
	}

	namespace SymbolParsers
	{
		template <typename ValueType>
		inline bool ParseDice(const std::string_view& s, ValueType& num_dices, ValueType& num_sides)
		{
			auto it_begin = std::to_address(std::begin(s));
			auto it_end = std::to_address(std::end(s));

			assert(it_begin != it_end);

			auto it = it_begin;

			for (++it; ::tolower(*it) != 'd'; ++it)
				;

			std::from_chars(it_begin, it, num_dices);

			it_begin = it + 1;
			it = it_end;

			std::from_chars(it_begin, it, num_sides);

			return true;
		}

		template <typename ValueType>
		inline bool ParseDice(const std::string_view& s, ValueType& num_dices, ValueType& num_sides, ValueType& bonus)
		{
			auto it_begin = std::to_address(std::begin(s));
			auto it_end = std::to_address(std::end(s));

			assert(it_begin != it_end);

			auto it = it_begin;

			for (++it; ::tolower(*it) != 'd'; ++it)
				;

			std::from_chars(it_begin, it, num_dices);

			for (++it; *it != '+'; ++it)
				;

			std::from_chars(it_begin, it, num_sides);

			it_begin = it + 1;
			it = it_end;

			std::from_chars(it_begin, it, bonus);

			return true;
		}

		template <typename ValueType>
		inline bool ParseEncounterRange(const std::string_view& s, ValueType& minimum, ValueType& maximum)
		{
			auto it_begin = std::to_address(std::begin(s));
			auto it_end = std::to_address(std::end(s));

			assert(it_begin != it_end);

			auto it = it_begin;

			for (++it; *it != '-'; ++it)
				;

			std::from_chars(it_begin, it, minimum);

			it_begin = it + 1;
			it = it_end;

			std::from_chars(it_begin, it, maximum);

			return true;
		}
	}
}
