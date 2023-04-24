#include "Engine/Graphics/Overlays.h"

#include "Engine/Engine.h"
#include "Engine/LOD.h"
#include "Engine/Party.h"
#include "Engine/Time.h"

#include "Engine/Graphics/IRender.h"

#include "Engine/Serialization/Deserializer.h"
#include "Engine/Serialization/Serializer.h"
#include "Engine/Serialization/LegacyImages.h"

#include "Engine/Tables/FrameTableInc.h"
#include "Engine/Tables/IconFrameTable.h"

#include "Engine/TurnEngine/TurnEngine.h"

#include "GUI/GUIWindow.h"


#include "Sprites.h"


struct OtherOverlayList* pOtherOverlayList = new OtherOverlayList;  // idb
struct OverlayList* pOverlayList = new OverlayList;

// inlined
//----- (mm6c::0045BD50) --------------------------------------------------
void OtherOverlayList::Reset()
{
	for (uint i = 0; i < 50; ++i)
	{
		pOverlays[i].Reset();
		}
}

//----- (004418B1) --------------------------------------------------------
int OtherOverlayList::_4418B1(int a2, int a3, int a4, int a5)
{
	return 0;
}

//----- (004418B6) --------------------------------------------------------
int OtherOverlayList::_4418B6(int uOverlayID, int16_t a3, int a4, int a5, int16_t a6)
{
	signed int v9;  // esi@6
	int16_t v11;    // dx@11

	for (uint i = 0; i < 50; ++i)
	{
		if (this->pOverlays[i].field_6 <= 0)
		{
			this->pOverlays[i].field_0 = 0;
			this->pOverlays[i].screen_space_y = 0;
			this->pOverlays[i].screen_space_x = 0;
			this->pOverlays[i].field_C = a3;
			v9 = 0;
			for (const auto& overlay_desc : pOverlayList->pOverlays)
			{
				if (overlay_desc.uOverlayID == uOverlayID)
					break;
				++v9;
			}
			this->pOverlays[i].field_2 = v9;
			this->pOverlays[i].sprite_frame_time = 0;
			if (a4)
				v11 = a4;
			else
				v11 = 8 * pSpriteFrameTable
				->pSpriteSFrames[pOverlayList->pOverlays[v9]
				.uSpriteFramesetID]
				.uAnimLength;
			this->pOverlays[i].field_6 = v11;
			this->pOverlays[i].field_10 = a5;
			this->pOverlays[i].field_E = a6;
			return true;
		}
	}
	return 0;
}

//----- (00441964) --------------------------------------------------------
void OtherOverlayList::DrawTurnBasedIcon()
{
	Icon* frame = nullptr;      // eax@12
	unsigned int v5;  // [sp-8h] [bp-Ch]@4

	if (current_screen_type != CURRENT_SCREEN::SCREEN_GAME || !pParty->bTurnBasedModeOn) return;

	if (pTurnEngine->turn_stage == TE_MOVEMENT)
	{
		// все персы отстрелялись(сжатый кулак)
		frame = pIconsFrameTable->GetFrame(
			pIconIDs_Turn[5 - pTurnEngine->uActionPointsLeft / 26],
			pEventTimer->uStartTime);
	}
	else if (pTurnEngine->turn_stage == TE_WAIT)
	{
		if (dword_50C998_turnbased_icon_1A)
			v5 = uIconID_TurnStart; //анимация руки(запуск пошагового режима)
		else
			v5 = uIconID_TurnHour; //группа ожидает(часы)
		frame = pIconsFrameTable->GetFrame(v5, dword_50C994);
	}
	else if (pTurnEngine->turn_stage == TE_ATTACK)
	{
		//группа атакует(ладонь)
		frame = pIconsFrameTable->GetFrame(uIconID_TurnStop,
			pEventTimer->uStartTime);
	}
	else
	{
		__debugbreak();
		return;
	}
	// if ( render->pRenderD3D )
	render->DrawTextureNew(394 / 640.0f, 288 / 480.0f, frame->GetTexture());
	/*else
	  render->DrawTextureIndexedAlpha(0x18Au, 0x120u, v7);*/
	if (dword_50C994 < dword_50C998_turnbased_icon_1A)
	{
		dword_50C994 += pEventTimer->uTimeElapsed;
		if ((signed int)dword_50C994 >= dword_50C998_turnbased_icon_1A)
			dword_50C998_turnbased_icon_1A = 0;
	}
}

//----- (00458D97) --------------------------------------------------------
void OverlayList::InitializeSprites()
{
	for (const auto& overlay_desc : pOverlays)
	{
		pSpriteFrameTable->InitializeSprite(overlay_desc.uSpriteFramesetID);
	}
}

//----- (00458DBC) --------------------------------------------------------
void OverlayList::ToFile()
{
	FILE* v2 = fopen(MakeDataPath("data", "doverlay.bin").c_str(), "wb");
	if (!v2)
		Error("Unable to save doverlay.bin!");
	const auto size = static_cast<uint32_t>(pOverlays.size());
	fwrite(&size, sizeof(size), 1, v2);
	fwrite(pOverlays.data(), sizeof(OverlayDesc), pOverlays.size(), v2);
	fclose(v2);
}

//----- (00458E08) --------------------------------------------------------
void OverlayList::FromFile(const Blob& data_mm6, const Blob& data_mm7, const Blob& data_mm8)
{
	Assert(!data_mm6);
	Assert(!data_mm8);

	pOverlays.clear();

	if (data_mm6)
	{
		BlobDeserializer stream(data_mm6);
		stream.ReadLegacyVector<data::mm6::OverlayDesc>(&pOverlays, Deserializer::Append);
	}

	if (data_mm7)
	{
		BlobDeserializer stream(data_mm7);
		stream.ReadLegacyVector<data::mm7::OverlayDesc>(&pOverlays, Deserializer::Append);
	}

	if (data_mm8)
	{
		BlobDeserializer stream(data_mm8);
		stream.ReadLegacyVector<data::mm8::OverlayDesc>(&pOverlays, Deserializer::Append);
	}

	Assert(!pOverlays.empty());
}

void OtherOverlay::Reset()
{
	this->field_0 = 0;
	this->field_2 = 0;
	this->sprite_frame_time = 0;
	this->field_6 = 0;
	this->screen_space_x = 0;
	this->screen_space_y = 0;
	this->field_C = 0;
	this->field_E = 0;
	this->field_10 = 65536;
}

OtherOverlay::OtherOverlay()
{
	this->Reset();
}
