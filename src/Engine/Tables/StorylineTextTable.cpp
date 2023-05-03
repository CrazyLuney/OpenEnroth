#include "Engine/Tables/StorylineTextTable.h"

#include "Utility/Strings.h"
#include "../LOD.h"

#include "Utility/MiniParser.hpp"

std::string pHistoryTXT_Raw;
struct StorylineText* pStorylineText;

//----- (00453E6D) --------------------------------------------------------
void StorylineText::Initialize()
{
	using namespace MiniParser;

	const auto blob = pEvents_LOD->LoadCompressedTexture("history.txt");

	for (const auto& data_line : GetLines(blob.string_view()) | std::views::drop(1) | std::views::take(28))
	{
		auto tokens = GetTokens(data_line);
		auto it = std::begin(tokens);

		std::size_t id;

		ParseToken(it, id);

		auto& story_line_info = StoryLine[id];

		ParseToken(it, story_line_info.pText, StripQuotes);
		// strange but in text here string not digit
		ParseToken(it, story_line_info.uTime);
		ParseToken(it, story_line_info.pPageTitle);
	}
}
