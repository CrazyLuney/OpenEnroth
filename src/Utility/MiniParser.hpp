#pragma once

namespace MiniParser
{
	using string_view_iterator = std::string_view::const_iterator;
	using string_view_regex_iterator = std::regex_iterator<string_view_iterator>;
	using string_view_regex_token_iterator = std::regex_token_iterator<string_view_iterator>;
	using string_view_match_results = std::match_results<string_view_iterator>;

	template <typename T>
	concept Number = std::integral<T> or std::floating_point<T>;
	template <typename T>
	concept Enum = std::is_enum_v<T>;
	template <typename T>
	concept NumberOrEnum = Number<T> or Enum<T>;

	template <typename T>
	concept ViewParserAction = requires (T&& callable, const std::string_view& s)
	{
		{ callable(s) } -> std::convertible_to<std::string_view>;
	};

	template <typename T>
	concept ValueParserActionCopy = requires (T&& callable, const std::string& s)
	{
		{ callable(s) } -> std::convertible_to<std::string>;
	};

	template <typename T>
	concept ValueParserActionInplace = requires (T&& callable, std::string& s)
	{
		{ callable(s) } -> std::same_as<void>;
	};

	template <typename T>
	concept ValueParserAction = ValueParserActionCopy<T> or ValueParserActionInplace<T>;

	template <typename T>
	concept AnyParserAction = ViewParserAction<T> or ValueParserAction<T>;

	template <typename T>
	concept MatchParserAction = requires (T&& callable, const string_view_match_results& mr)
	{
		{ callable(mr) } -> std::convertible_to<bool>;
	};

	template <typename T, typename ValueType>
	concept ValueMap =
		std::is_same_v<T, std::map<std::string, ValueType, typename T::key_compare, typename T::allocator_type>> or
		std::is_same_v<T, std::unordered_map<std::string, ValueType, typename T::hasher, typename T::key_equal, typename T::allocator_type>>;

	constexpr inline std::string_view Trim(const std::string_view& view)
	{
		if (view.length() > 0)
		{
			std::size_t l = 0;
			std::size_t r = view.length();
			while (l < r && std::isspace(view[l]))
				l++;
			while (l < r && std::isspace(view[r - 1]))
				r--;
			return view.substr(l, r - l);
		}
		return view;
	}

	constexpr inline std::string_view StripQuotes(const std::string_view& view)
	{
		if (view.length() > 1 && view.front() == '"' && view.back() == '"')
			return view.substr(1, view.length() - 2);
		return view;
	}

	constexpr inline std::string_view TrimAndStripQuotes(const std::string_view& view)
	{
		return StripQuotes(Trim(view));
	}

	constexpr inline void ToLowerInplace(std::string& s)
	{
		std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower);
	}

	constexpr inline std::string ToLower(const std::string& s)
	{
		std::string temp{ s };
		ToLowerInplace(temp);
		return temp;
	}

	constexpr inline void ToUpperInplace(std::string& s)
	{
		std::transform(std::begin(s), std::end(s), std::begin(s), ::toupper);
	}

	constexpr inline std::string ToUpper(const std::string& s)
	{
		std::string temp{ s };
		ToUpperInplace(temp);
		return temp;
	}

	namespace Detail
	{
		struct ViewParserActionsInvoker
		{
			template <AnyParserAction... Actions>
			void operator()(auto& s, Actions&&... actions) const
			{
				if constexpr (sizeof...(Actions) > 0)
				{
					Invoke(s, std::forward<Actions&&>(actions)...);
				}
			}
		private:
			template <ViewParserAction Action, AnyParserAction... TailActions>
			static void Invoke(auto& s, Action&& action, TailActions&&... tail_actions)
			{
				s = action(s);
				Invoke(s, std::forward<TailActions&&>(tail_actions)...);
			}

			template <ValueParserAction Action, AnyParserAction... TailActions>
			static void Invoke(auto& s, Action&&, TailActions&&... tail_actions)
			{
				Invoke(s, std::forward<TailActions&&>(tail_actions)...);
			}

			static void Invoke(...)
			{
			}
		};

		struct ValueParserActionsInvoker
		{
			template <AnyParserAction... Actions>
			void operator()(auto& s, Actions&&... actions) const
			{
				if constexpr (sizeof...(Actions) > 0)
				{
					Invoke(s, std::forward<Actions&&>(actions)...);
				}
			}
		private:
			template <ViewParserAction Action, AnyParserAction... TailActions>
			static void Invoke(auto& s, Action&&, TailActions&&... tail_actions)
			{
				Invoke(s, std::forward<TailActions&&>(tail_actions)...);
			}

			template <ValueParserActionCopy Action, AnyParserAction... TailActions>
			static void Invoke(auto& s, Action&& action, TailActions&&... tail_actions)
			{
				s = action(s);
				Invoke(s, std::forward<TailActions&&>(tail_actions)...);
			}

			template <ValueParserActionInplace Action, AnyParserAction... TailActions>
			static void Invoke(auto& s, Action&& action, TailActions&&... tail_actions)
			{
				action(s);
				Invoke(s, std::forward<TailActions&&>(tail_actions)...);
			}

			static void Invoke(...)
			{
			}
		};

		template <Number ValueType>
		inline bool Parse(const std::string_view& view, ValueType& value)
		{
			return std::from_chars(std::to_address(std::cbegin(view)), std::to_address(std::cend(view)), value).ec == std::errc();
		}

		template <Enum ValueType>
		inline bool Parse(const std::string_view& view, ValueType& value)
		{
			std::underlying_type_t<ValueType> raw_value;
			if (Parse(view, raw_value))
			{
				value = static_cast<ValueType>(raw_value);
				return true;
			}
			return false;
		}

		template <NumberOrEnum ValueType>
		inline bool Parse(const std::string_view& view, ValueType& value, const ValueType& default_value)
		{
			const bool result = Parse(view, value);
			if (!result)
				value = default_value;
			return result;
		}

		template <Enum ValueType, class MapType> requires ValueMap<MapType, ValueType>
		inline bool Parse(const std::string& s, ValueType& value, const MapType& value_map, const ValueType& default_value)
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

	template <NumberOrEnum ValueType>
	inline bool Parse(const std::string_view& view, ValueType& value)
	{
		return Detail::Parse(view, value);
	}

	template <NumberOrEnum ValueType>
	inline bool Parse(const string_view_match_results::value_type& sub_match, ValueType& value)
	{
		return Detail::Parse({ sub_match.first, sub_match.second }, value);
	}

	template <NumberOrEnum ValueType>
	inline bool Parse(const std::string_view& view, ValueType& value, const ValueType& default_value)
	{
		return Detail::Parse(view, value, default_value);
	}

	template <NumberOrEnum ValueType>
	inline bool Parse(const string_view_match_results::value_type& sub_match, ValueType& value, const ValueType& default_value)
	{
		return Detail::Parse({ sub_match.first, sub_match.second }, value, default_value);
	}

	template <Enum ValueType, class MapType>
	inline bool Parse(const std::string& s, ValueType& value, const MapType& value_map, const ValueType& default_value)
	{
		return Detail::Parse(s, value, value_map, default_value);
	}

	template <Enum ValueType, class MapType>
	inline bool Parse(const std::string_view& view, ValueType& value, const MapType& value_map, const ValueType& default_value)
	{
		return Detail::Parse({ view }, value, value_map, default_value);
	}

	template <Enum ValueType, class MapType>
	inline bool Parse(const string_view_match_results::value_type& sub_match, ValueType& value, const MapType& value_map, const ValueType& default_value)
	{
		return Detail::Parse(sub_match.str(), value, value_map, default_value);
	}

	template <class It> requires std::forward_iterator<It> or std::input_iterator<It>
	inline void SkipToken(It& it)
	{
		++it;
	}

	template <AnyParserAction... Actions>
	inline bool ParseToken(string_view_regex_iterator& it, std::string_view& value, Actions&&... actions)
	{
		value = { it->prefix().first, it->prefix().second };
		++it;
		Detail::ViewParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <class It, AnyParserAction... Actions> requires std::forward_iterator<It> or std::input_iterator<It>
	inline bool ParseToken(It& it, std::string_view& value, Actions&&... actions)
	{
		value = { std::ranges::begin(it), std::ranges::end(it) };
		++it;
		Detail::ViewParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <class It, AnyParserAction... Actions>
	inline bool ParseToken(It& it, std::string& value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		value.assign(token_view);
		Detail::ValueParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <class It, NumberOrEnum ValueType, AnyParserAction... Actions>
	inline bool ParseToken(It& it, ValueType& value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		const bool result = Parse(token_view, value);
		return result;
	}

	template <class It, MatchParserAction MatchAction, AnyParserAction... Actions>
	inline bool ParseToken(It& it, const std::regex& re, MatchAction&& match_action, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		string_view_match_results mr;
		if (std::regex_match(std::begin(token_view), std::end(token_view), mr, re))
			return match_action(mr);
		else
			return false;
	}

	template <Enum ValueType, class MapType, AnyParserAction... Actions> requires ValueMap<MapType, ValueType>
	inline bool ParseToken(string_view_regex_iterator& it, ValueType& value, const MapType& value_map, const ValueType& default_value, Actions&&... actions)
	{
		std::string token_value;
		ParseToken(it, token_value, std::forward<Actions&&>(actions)...);
		return Detail::Parse(token_value, value, value_map, default_value);
	}

	namespace
	{
		inline static const std::regex re_token_separator(R"(\t|\r\n|\r|\n|$)", std::regex::optimize);
		inline static const std::regex re_newline(R"(\r\n|\r|\n|$)", std::regex::optimize);
	}

	inline std::tuple<string_view_regex_iterator, string_view_regex_iterator> Tokenize(const std::string_view& view, const std::regex& re)
	{
		return { { std::begin(view), std::end(view), re, std::regex_constants::match_not_null }, {} };
	}

	inline std::tuple<string_view_regex_iterator, string_view_regex_iterator> Tokenize(const std::string_view& view)
	{
		return Tokenize(view, re_token_separator);
	}

	inline std::vector<std::string_view> Lines(const std::string_view& view)
	{
		auto [lines_begin, lines_end] { Tokenize(view, re_newline) };

		std::vector<std::string_view> lines;

		if (lines_begin == lines_end)
		{
			lines.push_back(view);
		}
		else
		{
			for (auto it = lines_begin; it != lines_end; )
			{
				auto prefix = it->prefix();
				auto suffix = it->suffix();

				if (prefix.length() > 0)
					// includes matched newline
					lines.emplace_back(prefix.first, suffix.first);
				else
					lines.emplace_back();

				if (++it == lines_end)
				{
					if (suffix.length() > 0)
						lines.emplace_back(suffix.first, suffix.second);
					break;
				}
			}
		}

		return lines;
	}

	inline std::string_view SkipLines(const std::string_view& view, std::size_t n)
	{
		if (n > 0)
		{
			auto [it, it_end] { Tokenize(view, re_newline) };

			while (n > 1 && it != it_end)
			{
				--n;
				++it;
			}

			if (it != it_end)
				return { it->suffix().first, it->suffix().second };
		}

		return view;
	}
}
