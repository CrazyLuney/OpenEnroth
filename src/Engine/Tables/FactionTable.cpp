#include "Engine/Tables/FactionTable.h"

#include "Engine/Engine.h"

#include "../LOD.h"

#include "Utility/MiniParser.hpp"

//----- (004547E4) --------------------------------------------------------
void FactionTable::Initialize()
{
	using namespace MiniParser;

	const auto blob = pEvents_LOD->LoadCompressedTexture("hostile.txt");

	auto data_lines = GetLines(blob.string_view()) | std::views::drop(1);
	auto it_data_line = std::begin(data_lines);

	for (std::size_t i = 0; i < 89; ++i, ++it_data_line)
	{
		auto tokens = GetTokens(*it_data_line);
		auto it = std::begin(tokens);

		DropToken(it);

		for (std::size_t j = 0; j < 89; ++j)
		{
			ParseToken(it, relations[j][i]);
		}
	}
}
