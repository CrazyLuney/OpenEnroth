#pragma once

namespace MiniParser
{
	using string_view_iterator = std::string_view::const_iterator;
	using string_view_regex_iterator = std::regex_iterator<string_view_iterator>;
	using string_view_regex_token_iterator = std::regex_token_iterator<string_view_iterator>;
	using string_view_match_results = std::match_results<string_view_iterator>;

	template <typename T>
	concept Number = std::integral<T> || std::floating_point<T>;
	template <typename T>
	concept Enum = std::is_enum_v<T>;
	template <typename T>
	concept NumberOrEnum = Number<T> || Enum<T>;

	template <typename T>
	concept ViewParserAction = requires (T&& callable, const std::string_view& s)
	{
		{ callable(s) } -> std::same_as<std::string_view>;
	};

	template <typename T>
	concept ValueParserActionCopy = requires (T&& callable, const std::string& s)
	{
		{ callable(s) } -> std::same_as<std::string>;
	};

	template <typename T>
	concept ValueParserActionInplace = requires (T&& callable, std::string& s)
	{
		{ callable(s) } -> std::same_as<void>;
	};

	template <typename T>
	concept ValueParserAction = ValueParserActionCopy<T> || ValueParserActionInplace<T>;

	template <typename T>
	concept AnyParserAction = ViewParserAction<T> || ValueParserAction<T>;

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

	template <Number ValueType>
	constexpr inline bool Parse(const std::string_view& view, ValueType& value)
	{
		return std::from_chars(std::to_address(std::cbegin(view)), std::to_address(std::cend(view)), value).ec == std::errc();
	}

	template <Enum ValueType>
	constexpr inline bool Parse(const std::string_view& view, ValueType& value)
	{
		std::underlying_type_t<ValueType> raw_value;
		if (Parse(view, raw_value))
		{
			value = static_cast<ValueType>(raw_value);
			return true;
		}
		return false;
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

		inline std::string_view GetTokenStringView(const string_view_regex_iterator& it)
		{
			return { it->prefix().first, it->prefix().second };
		}
	}

	inline void SkipToken(string_view_regex_iterator& it)
	{
		++it;
	}

	template <AnyParserAction... Actions>
	inline bool ParseToken(string_view_regex_iterator& it, std::string_view& value, Actions&&... actions)
	{
		value = Detail::GetTokenStringView(it);
		++it;
		Detail::ViewParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <AnyParserAction... Actions>
	inline bool ParseToken(string_view_regex_iterator& it, std::string& value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		value.assign(token_view);
		Detail::ValueParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <NumberOrEnum ValueType, AnyParserAction... Actions>
	inline bool ParseToken(string_view_regex_iterator& it, ValueType& value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		const bool result = Parse(token_view, value);
		return result;
	}

	inline std::tuple<string_view_regex_iterator, string_view_regex_iterator> Tokenize(const std::string_view& view, const std::regex& re)
	{
		return { { std::begin(view), std::end(view), re, std::regex_constants::match_not_null }, {} };
	}

	inline std::tuple<string_view_regex_iterator, string_view_regex_iterator> Tokenize(const std::string_view& view)
	{
		static const std::regex re_token_separator(R"(\t|\r\n|\r|\n|$)", std::regex::optimize);

		return Tokenize(view, re_token_separator);
	}

	inline std::string_view SkipLines(const std::string_view& view, std::size_t n)
	{
		static const std::regex re_newline(R"(\r\n|\r|\n|$)", std::regex::optimize);

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
