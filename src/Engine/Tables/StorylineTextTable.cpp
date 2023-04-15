#include "Engine/Tables/StorylineTextTable.h"

#include "Utility/String.h"
#include "../LOD.h"

std::string pHistoryTXT_Raw;
struct StorylineText* pStorylineText;

//----- (00453E6D) --------------------------------------------------------
void StorylineText::Initialize()
{
	char* test_string;

	pHistoryTXT_Raw = pEvents_LOD->LoadCompressedTexture("history.txt").string_view();
	strtok(pHistoryTXT_Raw.data(), "\r");

	StoreLine[0].pText = nullptr;
	StoreLine[0].pPageTitle = nullptr;
	StoreLine[0].uTime = 0;
	StoreLine[0].f_9 = 0;
	StoreLine[0].f_A = 0;
	StoreLine[0].f_B = 0;

	for (int i = 0; i < 28; ++i)
	{
		test_string = strtok(NULL, "\r") + 1;
		auto tokens = tokenize(test_string, '\t');

		StoreLine[i + 1].pText = removeQuotes(tokens[1]);
		StoreLine[i + 1].uTime =
			atoi(tokens[2]);  // strange but in text here string not digit
		StoreLine[i + 1].pPageTitle = removeQuotes(tokens[3]);
	}
}
