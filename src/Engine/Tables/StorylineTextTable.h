#pragma once

#pragma pack(push, 1)
struct StorylineRecord
{
	std::string pText;            // 0
	std::string pPageTitle;       // 4
	uint8_t uTime = 0;  // 8
	char f_9 = 0;
	char f_A = 0;
	char f_B = 0;
};
#pragma pack(pop)

/*  173 */
#pragma pack(push, 1)
struct StorylineText
{
	void Initialize();
	StorylineRecord StoryLine[29];
	int field_15C;
	// int field_0;
	// int field_4[87];
};
#pragma pack(pop)

extern std::string pHistoryTXT_Raw;
extern struct StorylineText* pStorylineText;
