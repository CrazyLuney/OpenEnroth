cmake_minimum_required(VERSION 3.20.4 FATAL_ERROR)

set(GUI_SOURCES
        GUIBountyHunting.cpp
        GUIButton.cpp
        GUIEnums.cpp
        GUIFont.cpp
        GUIProgressBar.cpp
        GUIWindow.cpp
        UI/Books/AutonotesBook.cpp
        UI/Books/CalendarBook.cpp
        UI/Books/JournalBook.cpp
        UI/Books/LloydsBook.cpp
        UI/Books/MapBook.cpp
        UI/Books/QuestBook.cpp
        UI/Books/TownPortalBook.cpp
        UI/Spellbook.cpp
        UI/UIArena.cpp
        UI/UIBooks.cpp
        UI/UICharacter.cpp
        UI/UIChest.cpp
        UI/UICredits.cpp
        UI/UIDialogue.cpp
        UI/UIGame.cpp
        UI/UIGameOver.cpp
        UI/UIGuilds.cpp
        UI/UIHouses.cpp
        UI/UIInventory.cpp
        UI/UIMainMenu.cpp
        UI/UIPartyCreation.cpp
        UI/UIPopup.cpp
        UI/UIQuickReference.cpp
        UI/UIRest.cpp
        UI/UISaveLoad.cpp
        UI/UIShops.cpp
        UI/UISpell.cpp
        UI/UIStatusBar.cpp
        UI/UITransition.cpp)

set(GUI_HEADERS
        GUIBountyHunting.h
        GUIButton.h
        GUIDialogues.h
        GUIEnums.h
        GUIFont.h
        GUIProgressBar.h
        GUIWindow.h
        UI/Books/AutonotesBook.h
        UI/Books/CalendarBook.h
        UI/Books/JournalBook.h
        UI/Books/LloydsBook.h
        UI/Books/MapBook.h
        UI/Books/QuestBook.h
        UI/Books/TownPortalBook.h
        UI/Spellbook.h
        UI/UIArena.h
        UI/UIBooks.h
        UI/UICharacter.h
        UI/UIChest.h
        UI/UICredits.h
        UI/UIDialogue.h
        UI/UIGame.h
        UI/UIGameOver.h
        UI/UIGuilds.h
        UI/UIHouseEnums.h
        UI/UIHouses.h
        UI/UIInventory.h
        UI/UIMainMenu.h
        UI/UIPartyCreation.h
        UI/UIPopup.h
        UI/UIQuickReference.h
        UI/UIRest.h
        UI/UISaveLoad.h
        UI/UIShops.h
        UI/UISpell.h
        UI/UIStatusBar.h
        UI/UITransition.h)

add_library(gui STATIC ${GUI_SOURCES} ${GUI_HEADERS})

target_link_libraries(gui arcomage engine_spells utility)

target_precompile_headers_reuse(gui utility)
