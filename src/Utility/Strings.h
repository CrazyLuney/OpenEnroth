#pragma once

std::string toLower(std::string_view text);
std::string toUpper(std::string_view text);
std::vector<char*> tokenize(char* input, const char separator);

//----- (00452C30) --------------------------------------------------------
inline char* removeQuotes(char* str)
{
	if (*str == '"')
	{
		str[strlen(str) - 1] = 0;
		return str + 1;
	}
	return str;
}

inline std::string trimRemoveQuotes(std::string str)
{
	while (str.length() > 0 && (str.front() == ' ' || str.front() == '"'))
	{
		str.erase(0, 1);
	}
	while (str.length() > 0 && (str.back() == ' ' || str.back() == '"'))
	{
		str.pop_back();
	}

	return str;
}

inline std::string_view trim(std::string_view s)
{
	size_t l = 0;
	size_t r = s.length();
	while (l < r && std::isspace(s[l]))
		l++;
	while (l < r && std::isspace(s[r - 1]))
		r--;
	return s.substr(l, r - l);
}

bool istarts_with(std::string_view s, std::string_view prefix);
bool iequals(std::string_view a, std::string_view b);
bool iless(std::string_view a, std::string_view b);
bool iequalsAscii(std::u8string_view a, std::u8string_view b);
bool ilessAscii(std::u8string_view a, std::u8string_view b);

struct ILess
{
	bool operator()(std::string_view a, std::string_view b) const
	{
		return iless(a, b);
	}
};

namespace Strings
{
	inline void ToLower(std::string& s)
	{
		std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower);
	}
}
