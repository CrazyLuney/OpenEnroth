#pragma once

class Blob;

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
		std::string_view::size_type l = 0;
		std::string_view::size_type r = view.length();
		while (l < r && std::isspace(view[l]))
			l++;
		while (l < r && std::isspace(view[r - 1]))
			r--;
		return view.substr(l, r - l);
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

	constexpr inline std::string_view LStripNonDigit(const std::string_view& s)
	{
		std::string_view::size_type l = 0;
		std::string_view::size_type r = s.length();
		while (l < r && !std::isdigit(s[l]))
			++l;
		return s.substr(l, r - l);
	}

	constexpr inline std::string_view RStripNonDigit(const std::string_view& s)
	{
		std::string_view::size_type l = 0;
		std::string_view::size_type r = s.length();
		while (l < r && !std::isdigit(s[r - 1]))
			--r;
		return s.substr(l, r - l);
	}

	constexpr inline std::string_view StripNonDigit(const std::string_view& s)
	{
		std::string_view::size_type l = 0;
		std::string_view::size_type r = s.length();
		while (l < r && !std::isdigit(s[l]))
			++l;
		while (l < r && !std::isdigit(s[r - 1]))
			--r;
		return s.substr(l, r - l);
	}

	namespace Detail
	{
		template <class S>
		concept StringOrStringView = std::same_as<S, std::string> or std::same_as<S, std::string_view>;

		enum class SplitStringIteratorPolicy
		{
			Default,
			StrictlyCRLF,
			CombineCRLF,
			CombineConsecutiveDelimiters,
		};

		template <StringOrStringView S, SplitStringIteratorPolicy Policy = SplitStringIteratorPolicy::Default>
		class SplitStringIterator final
		{
			using this_type = SplitStringIterator<S, Policy>;
			using string_type = S;
			using size_type = typename string_type::size_type;

			template <StringOrStringView OtherS, SplitStringIteratorPolicy OtherPolicy>
			friend class SplitStringIterator;
		public:
			// for ranges support
			using value_type = std::string_view;
			using difference_type = std::ptrdiff_t;

			SplitStringIterator() = default;
			SplitStringIterator(const string_type& s, const string_type& delim, size_type first = 0, size_type last = string_type::npos)
				: _string{ &s }
				, _delim{ &delim }
				, _first{ std::min(first, s.length()) }
				, _last{ std::min(last, s.length()) }
				, _delim_first{ _first }
				, _delim_last{ _first }
				, _valid{ _first < _last }
			{
				if constexpr (Policy == SplitStringIteratorPolicy::StrictlyCRLF)
				{
					assert(delim.length() == 2);
					assert(delim[0] == '\r');
					assert(delim[1] == '\n');
				}

				if constexpr (Policy == SplitStringIteratorPolicy::CombineCRLF)
				{
					assert(delim.find('\r') != string_type::npos);
					assert(delim.find('\n') != string_type::npos);
				}

				if (_valid)
					Advance();
			}

			constexpr std::string_view GetRest() const noexcept
			{
				assert(!!_string);

				if constexpr (std::is_same_v<string_type, std::string_view>)
				{
					return _string->substr(_first);
				}

				if constexpr (std::is_same_v<string_type, std::string>)
				{
					return { _string->data() + _first, _last - _first };
				}
			}

			constexpr std::string_view operator*() const noexcept
			{
				assert(!!_string);

				if constexpr (std::is_same_v<string_type, std::string_view>)
				{
					return _string->substr(_first, _delim_first - _first);
				}

				if constexpr (std::is_same_v<string_type, std::string>)
				{
					return { _string->data() + _first, _delim_first - _first };
				}
			}

			constexpr this_type& operator++() noexcept
			{
				if (_valid)
					Advance();
				return *this;
			}
			constexpr this_type operator++(int) noexcept
			{
				const this_type prev{ *this };
				if (_valid)
					Advance();
				return prev;
			}

			template <SplitStringIteratorPolicy OtherPolicy>
			constexpr bool operator==(const SplitStringIterator<S, OtherPolicy>& other) const noexcept
			{
				if (_valid != other._valid)
					return false;
				if (!_valid)
					return true;
				assert(_string == other._string);
				assert(_delim == other._delim);
				return
					_first == other._first &&
					_last == other._last &&
					_delim_first == other._delim_first &&
					_delim_last == other._delim_last;
			}

			template <SplitStringIteratorPolicy OtherPolicy>
			constexpr bool operator!=(const SplitStringIterator<S, OtherPolicy>& other) const noexcept
			{
				return !this->operator==(other);
			}
		private:
			SplitStringIterator(const string_type&, const string_type&&, size_type, size_type) = delete;
			SplitStringIterator(const string_type&&, const string_type&, size_type, size_type) = delete;
			SplitStringIterator(const string_type&&, const string_type&&, size_type, size_type) = delete;

			void Advance()
			{
				_first = _delim_last;

				if (_first >= _last)
				{
					_valid = false;
					return;
				}

				if constexpr (Policy == SplitStringIteratorPolicy::StrictlyCRLF)
				{
					_delim_first = _string->find(*_delim, _delim_last);
				}
				else
				{
					_delim_first = _string->find_first_of(*_delim, _delim_last);
				}
				

				if (_delim_first >= _last)
				{
					_delim_first = _last;
					_delim_last = _last;
					return;
				}

				if constexpr (Policy == SplitStringIteratorPolicy::StrictlyCRLF)
				{
					_delim_last = _delim_first + 2;
				}
				else
				{
					_delim_last = _delim_first + 1;
				}

				if constexpr (Policy == SplitStringIteratorPolicy::CombineCRLF)
				{
					if (const auto& s = *_string; s[_delim_first] == '\r' && _delim_last < _last && s[_delim_last] == '\n')
					{
						++_delim_last;
					}
				}

				if constexpr (Policy == SplitStringIteratorPolicy::CombineConsecutiveDelimiters)
				{
					_delim_last = _string->find_first_not_of(*_delim, _delim_first + 1);
				}

				if (_delim_last > _last)
					_delim_last = _last;
			}

			const string_type* _string = nullptr;
			const string_type* _delim = nullptr;
			size_type _first = std::string_view::npos;
			size_type _last = std::string_view::npos;
			size_type _delim_first = string_type::npos;
			size_type _delim_last = string_type::npos;
			bool _valid = false;
		};

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

		template <std::forward_iterator It>
		inline void GetTokenStringView(const It& it, std::string_view& view)
		{
			view = *it;
		}

		inline void GetTokenStringView(const string_view_regex_iterator& it, std::string_view& view)
		{
			view = { it->prefix().first, it->prefix().second };
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

	template <std::forward_iterator It>
	inline void SkipToken(It& it)
	{
		++it;
	}

	template <std::forward_iterator It>
	inline void DropTokens(It& it, std::size_t n = 1)
	{
		for (; n > 0; --n)
			++it;
	}

	template <std::forward_iterator It>
	inline void DropToken(It& it)
	{
		++it;
	}

	template <std::forward_iterator It, AnyParserAction... Actions>
	inline bool ParseToken(It& it, std::string_view& value, Actions&&... actions)
	{
		Detail::GetTokenStringView(it, value);
		++it;
		Detail::ViewParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <std::forward_iterator It, AnyParserAction... Actions>
	inline bool ParseToken(It& it, std::string& value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		value.assign(token_view);
		Detail::ValueParserActionsInvoker{}(value, std::forward<Actions&&>(actions)...);
		return true;
	}

	template <std::forward_iterator It, NumberOrEnum ValueType, AnyParserAction... Actions>
	inline bool ParseToken(It& it, ValueType& value, Actions&&... actions)
	{
		std::string_view token_view;
		ParseToken(it, token_view, std::forward<Actions&&>(actions)...);
		const bool result = Parse(token_view, value);
		return result;
	}

	template <std::forward_iterator It, MatchParserAction MatchAction, AnyParserAction... Actions>
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

	template <std::forward_iterator It, Enum ValueType, class MapType, AnyParserAction... Actions> requires ValueMap<MapType, ValueType>
	inline bool ParseToken(It& it, ValueType& value, const MapType& value_map, const ValueType& default_value, Actions&&... actions)
	{
		std::string token_value;
		ParseToken(it, token_value, std::forward<Actions&&>(actions)...);
		return Detail::Parse(token_value, value, value_map, default_value);
	}

	inline auto GetLines(const auto& s)
	{
		using string_type = std::remove_cvref_t<decltype(s)>;
		using iterator = Detail::SplitStringIterator<string_type, Detail::SplitStringIteratorPolicy::StrictlyCRLF>;

		static const string_type delimiter{ "\r\n" };

		iterator it{ s, delimiter };
		iterator it_end{};

		return std::ranges::subrange(it, it_end);
	}

	// NOTE: Blob::string_view() returns a temporary which will die inside this function
	inline auto GetLines(const Blob& blob) = delete;

	inline auto GetTokens(const auto& s)
	{
		using string_type = std::remove_cvref_t<decltype(s)>;
		using iterator = Detail::SplitStringIterator<string_type, Detail::SplitStringIteratorPolicy::Default>;

		static const string_type delimiter{ "\t" };

		iterator it{ s, delimiter };
		iterator it_end{};

		return std::ranges::subrange(it, it_end);
	}

	inline auto GetTokensVector(const auto& s)
	{
		auto tokens_range = GetTokens(s);
		std::vector<std::string_view> tokens;
		std::copy(std::begin(tokens_range), std::end(tokens_range), std::back_inserter(tokens));
		return tokens;
	}

	inline auto DropLines(const auto& s, std::size_t n)
	{
		using string_type = std::remove_cvref_t<decltype(s)>;
		using iterator = Detail::SplitStringIterator<string_type, Detail::SplitStringIteratorPolicy::StrictlyCRLF>;

		static const string_type delimiter{ "\r\n" };

		iterator it{ s, delimiter };
		iterator it_end{};

		for (; n > 0 && it != it_end; ++it, --n)
			;

		return it.GetRest();
	}
}
