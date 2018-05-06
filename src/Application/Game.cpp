#include "Application/Game.h"

#include <algorithm>
#include <string>

#include "Application/GameFactory.h"
#include "Application/GameMenu.h"

#include "Engine/AssetsManager.h"
#include "Engine/Engine.h"
#include "Engine/EngineFactory.h"
#include "Engine/Localization.h"
#include "Engine/Time.h"

#include "Engine/Events.h"
#include "Engine/LOD.h"
#include "Engine/Party.h"
#include "Engine/SaveLoad.h"

#include "Engine/Objects/Actor.h"
#include "Engine/Objects/Chest.h"
#include "Engine/Objects/ObjectList.h"
#include "Engine/Objects/SpriteObject.h"

#include "Engine/Graphics/DecalBuilder.h"
#include "Engine/Graphics/IRender.h"
#include "Engine/Graphics/Level/Decoration.h"
#include "Engine/Graphics/Outdoor.h"
#include "Engine/Graphics/Overlays.h"
#include "Engine/Graphics/PaletteManager.h"
#include "Engine/Graphics/Sprites.h"
#include "Engine/Graphics/Viewport.h"
#include "Engine/Graphics/Vis.h"

#include "Engine/Tables/FrameTableInc.h"

#include "Engine/TurnEngine/TurnEngine.h"

#include "Engine/Spells/CastSpellInfo.h"

#include "IO/Keyboard.h"
#include "IO/Mouse.h"

#include "Arcomage/Arcomage.h"

#include "Media/Audio/AudioPlayer.h"
#include "Media/MediaPlayer.h"

#include "GUI/GUIButton.h"
#include "GUI/GUIProgressBar.h"
#include "GUI/GUIWindow.h"
#include "GUI/UI/Books/AutonotesBook.h"
#include "GUI/UI/Books/CalendarBook.h"
#include "GUI/UI/Books/JournalBook.h"
#include "GUI/UI/Books/LloydsBook.h"
#include "GUI/UI/Books/MapBook.h"
#include "GUI/UI/Books/QuestBook.h"
#include "GUI/UI/Books/TownPortalBook.h"
#include "GUI/UI/Spellbook.h"
#include "GUI/UI/UIBooks.h"
#include "GUI/UI/UICharacter.h"
#include "GUI/UI/UICredits.h"
#include "GUI/UI/UIDialogue.h"
#include "GUI/UI/UIGame.h"
#include "GUI/UI/UIHouses.h"
#include "GUI/UI/UIMainMenu.h"
#include "GUI/UI/UIModal.h"
#include "GUI/UI/UIPartyCreation.h"
#include "GUI/UI/UIQuickReference.h"
#include "GUI/UI/UIRest.h"
#include "GUI/UI/UISaveLoad.h"
#include "GUI/UI/UIShops.h"
#include "GUI/UI/UIStatusBar.h"

void ShowMM7IntroVideo_and_LoadingScreen();
void IntegrityTest();

using Application::GameFactory;
using Application::Game;
using Application::Configuration;
using Engine_::EngineFactory;

int MM_Main(const char *pCmdLine) {
    GameFactory gameFactory;

    auto game = gameFactory.CreateGame(std::string(pCmdLine));
    game->Run();

    return 0;
}

bool Game::Configure(std::shared_ptr<const Configuration> config) {
    this->config = config;

    return true;
}



void Game::Run() {
    IntegrityTest();

    EngineFactory engineFactory;
    engine = engineFactory.CreateEngine(config->command_line);
    ::engine = engine;

    engine->Initialize();

    ShowMM7IntroVideo_and_LoadingScreen();

    dword_6BE364_game_settings_1 |= GAME_SETTINGS_4000;

    // logger->Warning(L"MM: entering main loop");
    while (true) {
        GUIWindow_MainMenu::Loop();
        uGameState = GAME_STATE_PLAYING;

        if (!Loop()) {
            break;
        }
    }

    if (engine) {
        engine->Deinitialize();
        engine = nullptr;
        ::engine = nullptr;
    }
}



bool Game::Loop() {
    while (1) {
        if (uGameState == GAME_FINISHED ||
            GetCurrentMenuID() == MENU_EXIT_GAME) {
            engine->Deinitialize();
            return false;
        } else if (GetCurrentMenuID() == MENU_SAVELOAD) {
            MainMenuLoad_Loop();
            if (GetCurrentMenuID() == MENU_LoadingProcInMainMenu) {
                uGameState = GAME_STATE_PLAYING;
                GameLoop();
            }
            break;
        } else if (GetCurrentMenuID() == MENU_NEWGAME) {
            pOtherOverlayList->Reset();
            if (!PartyCreationUI_Loop()) {
                break;
            }

            pParty->pPickedItem.uItemID = 0;

            pCurrentMapName = pStartingMapName;
            bFlashQuestBook = true;
            pMediaPlayer->PlayFullscreenMovie("Intro Post");
            SaveNewGame();
            if (engine->config->NoMargareth())
                _449B7E_toggle_bit(pParty->_quest_bits, PARTY_QUEST_EMERALD_MARGARETH_OFF, 1);
            GameLoop();
            if (uGameState == GAME_STATE_NEWGAME_OUT_GAMEMENU) {
                SetCurrentMenuID(MENU_NEWGAME);
                uGameState = GAME_STATE_PLAYING;
                continue;
            } else if (uGameState == GAME_STATE_GAME_QUITTING_TO_MAIN_MENU) {
                break;
            }
            assert(false && "Invalid game state");
        } else if (GetCurrentMenuID() == MENU_CREDITS) {
            pAudioPlayer->MusicStop();
            GUICredits::ExecuteCredits();
            break;
        } else if (GetCurrentMenuID() == MENU_5 ||
            GetCurrentMenuID() == MENU_LoadingProcInMainMenu) {
            uGameState = GAME_STATE_PLAYING;
            GameLoop();
        } else if (GetCurrentMenuID() == MENU_DebugBLVLevel) {
            mouse->ChangeActivation(0);
            pParty->Reset();
            pParty->CreateDefaultParty(true);

            __debugbreak();
            /*extern void CreateDefaultBLVLevel();
            CreateDefaultBLVLevel();

            OPENFILENAMEA ofn;
            if ( !GetOpenFileNameA((LPOPENFILENAMEA)&ofn) )
            {
            pMouse->ChangeActivation(1);
            break;
            }
            _chdir("..\\");
            strcpy(pCurrentMapName, ofn.lpstrFileTitle);*/
            mouse->ChangeActivation(1);
            GameLoop();
        }
        if (uGameState == GAME_STATE_LOADING_GAME) {
            SetCurrentMenuID(MENU_5);
            uGameState = GAME_STATE_PLAYING;
            continue;
        }
        if (uGameState == GAME_STATE_NEWGAME_OUT_GAMEMENU) {
            SetCurrentMenuID(MENU_NEWGAME);
            uGameState = GAME_STATE_PLAYING;
            continue;
        }
        if (uGameState ==
            GAME_STATE_GAME_QUITTING_TO_MAIN_MENU) {  // from the loaded game
            pAudioPlayer->StopChannels(-1, -1);
            uGameState = GAME_STATE_PLAYING;
            break;
        }
    }

    return true;
}



void ShowMM7IntroVideo_and_LoadingScreen() {
    bGameoverLoop = true;

    render->PresentBlackScreen();
    if (!engine->config->NoVideo()) {
        if (!engine->config->no_logo) {
            pMediaPlayer->PlayFullscreenMovie("3dologo");
            pMediaPlayer->PlayFullscreenMovie("new world logo");
            pMediaPlayer->PlayFullscreenMovie("jvc");
        }
        if (!engine->config->no_intro) {
            pMediaPlayer->PlayFullscreenMovie("Intro");
        }
    }

    Image *tex = assets->GetImage_PCXFromIconsLOD("mm6title.pcx");

    render->BeginScene();
    render->DrawTextureNew(0, 0, tex);

    DrawMM7CopyrightWindow();

    render->EndScene();
    render->Present();

    tex->Release();
    tex = nullptr;

    bGameoverLoop = false;
}




Image *gamma_preview_image = nullptr;  // 506E40

void Game_StartDialogue(unsigned int actor_id) {
    if (uActiveCharacter) {
        viewparams->field_48 = 1;

        pMessageQueue_50CBD0->Flush();

        dword_5B65D0_dialogue_actor_npc_id = pActors[actor_id].sNPC_ID;
        GameUI_InitializeDialogue(&pActors[actor_id], true);
    }
}

void Game_StartHirelingDialogue(unsigned int hireling_id) {
    if (bNoNPCHiring || current_screen_type != 0) return;

    pMessageQueue_50CBD0->Flush();

    uint hireling_slot = 0;
    char buf[1024];
    for (uint i = 0; i < 2; ++i) {
        if (pParty->pHirelings[i].pName) buf[hireling_slot++] = i;
    }

    for (uint i = 0; i < pNPCStats->uNumNewNPCs; ++i) {
        NPCData *npc = &pNPCStats->pNewNPCData[i];
        if (npc->Hired() &&
            (!pParty->pHirelings[0].pName ||
             strcmp(npc->pName, pParty->pHirelings[0].pName)) &&
            (!pParty->pHirelings[1].pName ||
             strcmp(npc->pName, pParty->pHirelings[1].pName))) {
            buf[hireling_slot++] = i + 2;
        }
    }

    if ((signed int)hireling_id + (signed int)pParty->hirelingScrollPosition <
        hireling_slot) {
        Actor actor;
        memset(&actor, 0, sizeof(actor));
        actor.sNPC_ID += -1 - pParty->hirelingScrollPosition - hireling_id;
        GameUI_InitializeDialogue(&actor, true);
    }
}

void Game::CloseTargetedSpellWindow() {
    if (pGUIWindow_CastTargetedSpell) {
        if (current_screen_type == SCREEN_CHARACTERS) {
            mouse->SetCursorImage("MICON2");
        } else {
            pGUIWindow_CastTargetedSpell->Release();  // test to fix enchanting issue
            pGUIWindow_CastTargetedSpell = nullptr;  // test to fix enchanting issue
            mouse->SetCursorImage("MICON1");
            game_ui_status_bar_event_string_time_left = 0;
            _50C9A0_IsEnchantingInProgress = 0;
            back_to_game();
        }
    }
}

void Game::OnEscape() {
    CloseTargetedSpellWindow();

    // if ((signed int)uActiveCharacter < 1 || (signed int)uActiveCharacter > 4)

    uActiveCharacter =
        pParty->GetNextActiveCharacter();  // always check this - could leave
                                           // shops with characters who couldnt
                                           // act sctive

    if (pGUIWindow_CurrentMenu == window_SpeakInHouse) {
        window_SpeakInHouse = nullptr;
    }
    if (pGUIWindow_CurrentMenu != nullptr) {
        pGUIWindow_CurrentMenu->Release();  // check this
        pGUIWindow_CurrentMenu = nullptr;
    }
    pEventTimer->Resume();
    current_screen_type = SCREEN_GAME;
    viewparams->bRedrawGameUI = true;
}

void Game::EventLoop() {
    unsigned int v2;            // edx@7
    GUIWindow *pWindow2;        // ecx@248
    int v37;                    // eax@341
    int v38;                    // eax@358
    char *v41;                  // eax@380
    int v42;                    // eax@396
    signed int v44;             // eax@398
    int v45;                    // edx@398
    signed int v46;             // ecx@398
    char v47;                   // zf@399
    char v48;                   // zf@405
    BLVFace *pBLVFace;          // ecx@410
    ODMFace *pODMFace;          // ecx@412
    CastSpellInfo *pSpellInfo;  // ecx@415
    __int16 v53;                // ax@431
    int v54;                    // eax@432
    int v55;                    // ecx@432
    int v56;                    // edx@432
    int v57;                    // eax@432
    Player *pPlayer;            // edx@442
    unsigned int pMapNum;       // eax@445
    signed int v60;             // ST64_4@459
    __int16 v63;                // dx@479
    unsigned int v64;           // eax@486
    int v65;                    // ecx@486
    int v66;                    // eax@488
    char *v67;                  // eax@489
    __int16 v68;                // dx@498
    int v70;                    // eax@525
    int v71;                    // edi@527
    NPCData *pNPCData3;         // esi@527
    char *v73;                  // ecx@533
    signed int v74;             // edi@535
    int v75;                    // eax@535
    int v76;                    // esi@535
    int v77;                    // eax@537
    Player *pPlayer2;           // ecx@549
                                // signed int v81; // eax@552
    signed int v83;             // ecx@554
    signed int v84;             // ecx@554
    GUIButton *pButton;         // eax@578
    unsigned int v86;           // eax@583
    const char *v87;            // ecx@595
    const char *v88;            // ecx@596
    unsigned int v90;           // eax@602
    int v91;                    // edx@605
    int v92;                    // eax@605
    int v93;                    // edx@605
    int pPlayerNum;             // edx@611
    int v95;                    // eax@611
    unsigned int v97;           // eax@624
    int v98;                    // eax@636
    int v103;                   // eax@671
    Player *pPlayer4;           // ecx@718
    int v105;                   // eax@718
    Player *pPlayer5;           // ST78_4@758
    unsigned int v115;          // eax@764
    unsigned int v118;          // eax@785
    unsigned int v119;          // ecx@786
                        //    unsigned int v121; // [sp-28h] [bp-624h]@711
                        //    unsigned int v123; // [sp-24h] [bp-620h]@711
                        //    unsigned int v125; // [sp-20h] [bp-61Ch]@711
    int v127;  // [sp-1Ch] [bp-618h]@107
               //    unsigned int v128; // [sp-1Ch] [bp-618h]@711
    GUIButton
        *pButton2;  // [sp-4h] [bp-600h]@59
                    //    KeyToggleType pKeyToggleType; // [sp+0h] [bp-5FCh]@287
    Player *pPlayer7;             // [sp+14h] [bp-5E8h]@373
    Player *pPlayer8;             // [sp+14h] [bp-5E8h]@377
    Player *pPlayer9;             // [sp+14h] [bp-5E8h]@455
    int thisg;                    // [sp+14h] [bp-5E8h]@467
    int thish;                    // [sp+14h] [bp-5E8h]@528
    signed int thisi;             // [sp+14h] [bp-5E8h]@535
    MapInfo *pMapInfo;            // [sp+14h] [bp-5E8h]@604
    Player *pPlayer10;            // [sp+14h] [bp-5E8h]@641
    int uMessageParam;            // [sp+18h] [bp-5E4h]@7
    int uAction;                  // [sp+1Ch] [bp-5E0h]@18
    NPCData *pNPCData4;           // [sp+20h] [bp-5DCh]@23
    unsigned int uNumSeconds;     // [sp+24h] [bp-5D8h]@18
                                  //    char v197; // [sp+2Bh] [bp-5D1h]@101
    enum UIMessageType uMessage;  // [sp+2Ch] [bp-5D0h]@7
    unsigned int v199;            // [sp+30h] [bp-5CCh]@7
    char *v200;                   // [sp+34h] [bp-5C8h]@518
    int v213;                     // [sp+98h] [bp-564h]@385
    char pOut[32];                // [sp+BCh] [bp-540h]@370
    int v217[9];                  // [sp+158h] [bp-4A4h]@652
    char Str2[128];               // [sp+238h] [bp-3C4h]@527
    Actor actor;                  // [sp+2B8h] [bp-344h]@4
    int currHour;

    dword_50CDC8 = 0;
    if (!pEventTimer->bPaused) {
        pParty->sEyelevel = pParty->uDefaultEyelevel;
        pParty->uPartyHeight = pParty->uDefaultPartyHeight;
    }
    if (bDialogueUI_InitializeActor_NPC_ID) {
        // Actor::Actor(&actor);
        memset(&actor, 0, 0x344u);
        dword_5B65D0_dialogue_actor_npc_id = bDialogueUI_InitializeActor_NPC_ID;
        actor.sNPC_ID = bDialogueUI_InitializeActor_NPC_ID;
        GameUI_InitializeDialogue(&actor, false);
        bDialogueUI_InitializeActor_NPC_ID = 0;
    }
    if (!pMessageQueue_50CBD0->Empty()) {
        // v1 = "";
        while (2) {
            if (pMessageQueue_50CBD0->Empty()) {
                break;
            }

            pMessageQueue_50CBD0->PopMessage(&uMessage, &uMessageParam,
                                             (int *)&v199);
            switch (uMessage) {
                case UIMSG_ChangeGameState:
                    uGameState = GAME_FINISHED;
                    continue;
                case UIMSG_PlayArcomage:
                    BackToHouseMenu();
                    pArcomageGame->bGameInProgress = 1;
                    ArcomageGame::PrepareArcomage();
                    continue;

                case UIMSG_StartNPCDialogue:
                    Game_StartDialogue(uMessageParam);
                    continue;
                case UIMSG_StartHireling1Dialogue:
                case UIMSG_StartHireling2Dialogue:
                    Game_StartHirelingDialogue(uMessage -
                                               UIMSG_StartHireling1Dialogue);
                    continue;
                case UIMSG_BuyInShop_Identify_Repair:
                    UIShop_Buy_Identify_Repair();
                    continue;
                case UIMSG_ClickNPCTopic:
                    ClickNPCTopic(uMessageParam);
                    continue;
                case UIMSG_SelectShopDialogueOption:
                    OnSelectShopDialogueOption(uMessageParam);
                    continue;
                case UIMSG_SelectNPCDialogueOption:
                    OnSelectNPCDialogueOption((DIALOGUE_TYPE)uMessageParam);
                    continue;
                case UIMSG_ClickHouseNPCPortrait:
                    _4B4224_UpdateNPCTopics(uMessageParam);
                    continue;
                    // case UIMSG_StartNewGame:
                    // Game_StartNewGameWhilePlaying(uMessageParam); continue;
                    // case UIMSG_Game_OpenLoadGameDialog:
                    // Game_OpenLoadGameDialog(); continue; case UIMSG_Quit:
                    // Game_QuitGameWhilePlaying(uMessageParam); continue;
                case UIMSG_80:
                    __debugbreak();
                    pGUIWindow_CurrentMenu->Release();
                    current_screen_type = SCREEN_OPTIONS;
                    __debugbreak();  // pGUIWindow_CurrentMenu =
                                     // GUIWindow::Create(0, 0,
                                     // window->GetWidth(), window->GetHeight(),
                                     // WINDOW_8, 0, 0);
                    continue;
                case UIMSG_Cancel:
                    new OnCancel(350, 302, 106, 42, (int)pBtnCancel);
                    continue;
                case UIMSG_OpenQuestBook:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME)
                        pGUIWindow_CurrentMenu->Release();
                    pGUIWindow_CurrentMenu = new GUIWindow_QuestBook();
                    continue;
                case UIMSG_OpenAutonotes:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME)
                        pGUIWindow_CurrentMenu->Release();
                    pGUIWindow_CurrentMenu = new GUIWindow_AutonotesBook();
                    continue;
                case UIMSG_OpenMapBook:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME)
                        pGUIWindow_CurrentMenu->Release();
                    pGUIWindow_CurrentMenu = new GUIWindow_MapBook();
                    continue;
                case UIMSG_OpenCalendar:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME)
                        pGUIWindow_CurrentMenu->Release();
                    pGUIWindow_CurrentMenu = new GUIWindow_CalendarBook();
                    continue;
                case UIMSG_OpenHistoryBook:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME)
                        pGUIWindow_CurrentMenu->Release();
                    pGUIWindow_CurrentMenu = new GUIWindow_JournalBook();
                    continue;
                case UIMSG_Escape:  // нажатие Escape and return to game
                    back_to_game();
                    pMessageQueue_50CBD0->Flush();
                    switch (current_screen_type) {
                        case SCREEN_E:
                            __debugbreak();
                        case SCREEN_NPC_DIALOGUE:
                        case SCREEN_CHEST:
                        case SCREEN_CHEST_INVENTORY:
                        case SCREEN_CHANGE_LOCATION:
                        case SCREEN_INPUT_BLV:
                        case SCREEN_QUICK_REFERENCE:
                            if (dword_50CDC8) break;
                            CloseWindowBackground();
                            uMessageParam = 1;
                            break;
                        case SCREEN_HOUSE:
                            if (!dword_50CDC8) {
                                CloseWindowBackground();
                                uMessageParam = 1;
                                break;
                            }
                            break;
                    }
                    if (pModalWindow) {
                        pModalWindow->Release();
                        pModalWindow = nullptr;
                        continue;
                    }
                    render->ClearZBuffer(0, 479);
                    viewparams->bRedrawGameUI = true;
                    viewparams->field_48 = 1;
                    if (current_screen_type == SCREEN_GAME) {
                        if (!pGUIWindow_CastTargetedSpell) {  // Draw Menu
                            dword_6BE138 = -1;
                            new OnButtonClick2(0x25Au, 0x1C2u, 0, 0,
                                               (int)pBtn_GameSettings, String(),
                                               false);

                            pMessageQueue_50CBD0->Flush();
                            menu->MenuLoop();
                        } else {
                            pGUIWindow_CastTargetedSpell->Release();
                            pGUIWindow_CastTargetedSpell = 0;
                            mouse->SetCursorImage("MICON1");
                            game_ui_status_bar_event_string_time_left = 0;
                            _50C9A0_IsEnchantingInProgress = 0;
                            back_to_game();
                        }
                        continue;
                    } else if (current_screen_type ==
                               SCREEN_MENU) {
/*
    stru_506E40.Release();
    Game_OnEscape();
*/
                        break;
                    } else if (
                        current_screen_type == SCREEN_SAVEGAME ||
                        current_screen_type == SCREEN_LOADGAME) {
/*
                        // crt_deconstruct_ptr_6A0118();
                        stru_506E40.Release();
                        Game_OnEscape();
*/
                        break;
                    } else if (
                        current_screen_type == SCREEN_OPTIONS) {
/*
                        options_menu_skin.Relaease();
                        OS_SetAppInt("soundflag",
                        (char)uSoundVolumeMultiplier);
                        OS_SetAppInt("musicflag",
                        (char)uMusicVolimeMultiplier);
                        OS_SetAppInt("CharVoices",
                        (char)uVoicesVolumeMultiplier);
                        OS_SetAppInt("WalkSound", bWalkSound);
                        OS_SetAppInt("ShowDamage",
                        bShowDamage);
                        // OS_SetAppInt("graphicsmode",
                        (unsigned
                        __int8)byte_6BE388_graphicsmode);
                        OS_SetAppInt("valAlwaysRun",
                        bAlwaysRun);
                        OS_SetAppInt("FlipOnExit",
                        bFlipOnExit); if (uTurnSpeed == 0)
                        OS_SetAppInt("TurnDelta", 3);
                        else if (uTurnSpeed == 64)
                        OS_SetAppInt("TurnDelta", 2);
                        else if (uTurnSpeed == 128)
                        OS_SetAppInt("TurnDelta", 1);
                        stru_506E40.Release();
                        Game_OnEscape();
*/
                        break;
                    } else if (
                        current_screen_type == SCREEN_VIDEO_OPTIONS) {
/*
                            // if ( render->pRenderD3D ) {
                            OS_SetAppInt("Colored Lights",
                            render->bUseColoredLights);
                            OS_SetAppInt("Tinting",
                            render->bTinting);
                            OS_SetAppInt("Bloodsplats",
                            (LOBYTE(engine->uFlags2) >> 5)
                            & 1);
                            }

                            stru_506E40.Release();
                            Game_OnEscape();
*/
                        break;
                    } else if (current_screen_type == SCREEN_KEYBOARD_OPTIONS) {
                        /*v197 = 1;
                        pKeyBindingFlag = false;
                        for (uint i = 0; i < 28; ++i)
                        {
                        if (GameMenuUI_InvaligKeyBindingsFlags[i])
                        pKeyBindingFlag = true;
                        }
                        if (!pKeyBindingFlag)
                        {
                        memset(&game_ui_options_controls, 0, 20);
                        for (uint i = 0; i < 28; ++i)
                        {
                        if (pKeyActionMap->GetActionVKey((enum InputAction)i) !=
                        pPrevVirtualCidesMapping[i])
                        {
                        if (v197)
                        {
                        GUI_ReplaceHotkey(pKeyActionMap->GetActionVKey((enum
                        InputAction)i), LOBYTE(pPrevVirtualCidesMapping[i]), 1);
                        v197 = 0;
                        }
                        else
                        GUI_ReplaceHotkey(pKeyActionMap->GetActionVKey((enum
                        InputAction)i), LOBYTE(pPrevVirtualCidesMapping[i]), 0);
                        }
                        if (i > 3 && i != 25 && i != 26)
                        pKeyToggleType = TOGGLE_OneTimePress;
                        else
                        pKeyToggleType = TOGGLE_Continuously;
                        pKeyActionMap->SetKeyMapping(i,
                        pPrevVirtualCidesMapping[i], pKeyToggleType);
                        }
                        pKeyActionMap->StoreMappings();
                        stru_506E40.Release();
                        }
                        else
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 
                        0);

                        Game_OnEscape();*/
                        break;
                    } else {
                        if (current_screen_type > SCREEN_67) {
                            if (current_screen_type == SCREEN_QUICK_REFERENCE) {
                                OnEscape();
                                continue;
                            }
                        } else {
                            if (current_screen_type < SCREEN_64) {
                                switch (current_screen_type) {
                                    case SCREEN_CASTING:
                                        if (some_active_character) {
                                            uActiveCharacter =
                                                some_active_character;
                                            uActiveCharacter =
                                                pParty
                                                    ->GetNextActiveCharacter();
                                            some_active_character = 0;
                                            if (pParty->bTurnBasedModeOn)
                                                pTurnEngine
                                                    ->ApplyPlayerAction();
                                            _50C9D0_AfterEnchClickEventId = 0;
                                            _50C9D4_AfterEnchClickEventSecondParam =
                                                0;
                                            _50C9D8_AfterEnchClickEventTimeout =
                                                0;
                                        }
                                        if (ptr_50C9A4_ItemToEnchant &&
                                            ptr_50C9A4_ItemToEnchant->uItemID) {
                                            ptr_50C9A4_ItemToEnchant
                                                ->uAttributes &= 0xFFFFFF0F;
                                            _50C9A8_item_enchantment_timer = 0;
                                            ptr_50C9A4_ItemToEnchant = nullptr;
                                        }
                                        OnEscape();
                                        continue;
                                    case SCREEN_BOOKS:
                                        if (pBooksButtonOverlay != nullptr) {
                                            pBooksButtonOverlay->Release();
                                            // crt_deconstruct_ptr_6A0118();
                                            pBooksButtonOverlay = 0;
                                        }
                                        pEventTimer->Resume();
                                        OnEscape();
                                        continue;
                                    case SCREEN_CHEST_INVENTORY:
                                        current_screen_type = SCREEN_CHEST;
                                        continue;
                                    case SCREEN_CHEST:
                                        pWindow2 = pChestWindow;
                                        pWindow2->Release();
                                        current_screen_type = SCREEN_GAME;
                                        viewparams->bRedrawGameUI = 1;
                                        pEventTimer->Resume();
                                        continue;
                                    case SCREEN_19:
                                        __debugbreak();
                                        pWindow2 = ptr_507BC8;
                                        pWindow2->Release();
                                        current_screen_type = SCREEN_GAME;
                                        viewparams->bRedrawGameUI = 1;
                                        pEventTimer->Resume();
                                        continue;
                                    case SCREEN_REST:  // close rest screen
                                        if (_506F14_resting_stage) {
                                            Rest(_506F18_num_minutes_to_sleep);
                                            pParty->pPlayers[3].SetAsleep(
                                                GameTime(0));
                                            pParty->pPlayers[2].SetAsleep(
                                                GameTime(0));
                                            pParty->pPlayers[1].SetAsleep(
                                                GameTime(0));
                                            pParty->pPlayers[0].SetAsleep(
                                                GameTime(0));
                                        }
                                        if (rest_ui_sky_frame_current) {
                                            rest_ui_sky_frame_current
                                                ->Release();
                                            rest_ui_sky_frame_current = nullptr;
                                        }

                                        if (rest_ui_hourglass_frame_current) {
                                            rest_ui_hourglass_frame_current
                                                ->Release();
                                            rest_ui_hourglass_frame_current =
                                                nullptr;
                                        }

                                        if (uCurrentlyLoadedLevelType ==
                                            LEVEL_Outdoor) {
                                            pOutdoor->UpdateSunlightVectors();
                                            pOutdoor->UpdateFog();
                                        }
                                        _506F18_num_minutes_to_sleep = 0;
                                        _506F14_resting_stage = 0;
                                        OnEscape();
                                        continue;
                                    case SCREEN_E:
                                        __debugbreak();
                                        pGUIWindow_CurrentMenu->Release();
                                        current_screen_type = SCREEN_HOUSE;
                                        continue;
                                    case SCREEN_HOUSE:
                                        if (uDialogueType) uDialogueType = 0;
                                        if (uGameState ==
                                            GAME_STATE_CHANGE_LOCATION) {
                                            while (HouseDialogPressCloseBtn());
                                        } else {
                                            if (HouseDialogPressCloseBtn())
                                                continue;
                                        }
                                        GetHouseGoodbyeSpeech();
                                        pAudioPlayer->PlaySound(
                                            SOUND_WoodDoorClosing, 814, 0, -1, 0, 0);
                                        pMediaPlayer->Unload();
                                        pGUIWindow_CurrentMenu =
                                            window_SpeakInHouse;

                                        OnEscape();
                                        continue;
                                    case SCREEN_INPUT_BLV:  // click escape
                                        if (uCurrentHouse_Animation == 153)
                                            PlayHouseSound(
                                                0x99u, HouseSound_Greeting_2);
                                        pMediaPlayer->Unload();
                                        if (npcIdToDismissAfterDialogue) {
                                            pParty->hirelingScrollPosition = 0;
                                            pNPCStats
                                                ->pNewNPCData
                                                    [npcIdToDismissAfterDialogue]
                                                .uFlags &= 0xFFFFFF7F;
                                            pParty->CountHirelings();
                                            viewparams->bRedrawGameUI = true;
                                            npcIdToDismissAfterDialogue = 0;
                                        }
                                        DialogueEnding();
                                        current_screen_type = SCREEN_GAME;
                                        viewparams->bRedrawGameUI = true;
                                        continue;
                                    case SCREEN_NPC_DIALOGUE:  // click escape
                                        if (npcIdToDismissAfterDialogue) {
                                            pParty->hirelingScrollPosition = 0;
                                            pNPCStats
                                                ->pNewNPCData
                                                    [npcIdToDismissAfterDialogue]
                                                .uFlags &= 0xFFFFFF7F;
                                            pParty->CountHirelings();
                                            viewparams->bRedrawGameUI = true;
                                            npcIdToDismissAfterDialogue = 0;
                                        }
                                        // goto LABEL_317;
                                        DialogueEnding();
                                        current_screen_type = SCREEN_GAME;
                                        viewparams->bRedrawGameUI = true;
                                        continue;
                                    case SCREEN_BRANCHLESS_NPC_DIALOG:  // click
                                                                        // escape
                                        GameUI_StatusBar_ClearEventString();

                                        sub_4452BB();
                                        DialogueEnding();
                                        current_screen_type = SCREEN_GAME;
                                        viewparams->bRedrawGameUI = true;
                                        continue;
                                    case SCREEN_CHANGE_LOCATION:  // click
                                                                  // escape
                                        if (pParty->vPosition.x < -22528)
                                            pParty->vPosition.x = -22528;
                                        if (pParty->vPosition.x > 22528)
                                            pParty->vPosition.x = 22528;
                                        if (pParty->vPosition.y < -22528)
                                            pParty->vPosition.y = -22528;
                                        if (pParty->vPosition.y > 22528)
                                            pParty->vPosition.y = 22528;
                                        DialogueEnding();
                                        current_screen_type = SCREEN_GAME;
                                        viewparams->bRedrawGameUI = true;
                                        continue;
                                    case SCREEN_VIDEO:
                                        pMediaPlayer->Unload();
                                        continue;
                                    case SCREEN_CHARACTERS:
                                        CharacterUI_ReleaseButtons();
                                        ReleaseAwardsScrollBar();
                                        OnEscape();
                                        continue;
                                    case SCREEN_SPELL_BOOK:
                                        OnEscape();
                                        continue;

                                    default:
                                        __debugbreak();  // which GAME_MENU is
                                                         // this?
                                        OnEscape();
                                        continue;
                                }
                                __debugbreak();  // which GAME_MENU is this?
                                OnEscape();
                                continue;
                            }
                            __debugbreak();  // which GAME_MENU is this?
                            CharacterUI_ReleaseButtons();
                            ReleaseAwardsScrollBar();
                        }
                        __debugbreak();  // which GAME_MENU is this?
                        OnEscape();
                        continue;
                    }
                    continue;

                case UIMSG_ScrollNPCPanel:  // Right and Left button for
                                            // NPCPanel
                    if (uMessageParam) {
                        new OnButtonClick2(626, 179, 0, 0, (int)pBtn_NPCRight);
                        v37 = (pParty->pHirelings[0].pName != 0) +
                              (pParty->pHirelings[1].pName != 0) +
                              (unsigned __int8)pParty->field_70A - 2;
                        if (pParty->hirelingScrollPosition < v37) {
                            ++pParty->hirelingScrollPosition;  // ??? maybe
                                                               // number of the
                                                               // first cell???
                            if (pParty->hirelingScrollPosition >= v37)
                                pParty->hirelingScrollPosition =
                                    (pParty->pHirelings[0].pName != 0) +
                                    (pParty->pHirelings[1].pName != 0) +
                                    pParty->field_70A - 2;
                        }
                    } else {
                        new OnButtonClick2(469, 179, 0, 0, (int)pBtn_NPCLeft);
                        /*if ( pParty->field_709 )
                        {
                        --pParty->field_709;
                        if ( pParty->field_709 < 1 )
                        pParty->field_709 = 0;
                        }*/
                    }
                    GameUI_DrawHiredNPCs();
                    continue;

                case UIMSG_TransitionUI_Confirm:
                    pMessageQueue_50CBD0->Flush();
                    dword_50CDC8 = 1;
                    sub_42FBDD();
                    PlayHouseSound(
                        uCurrentHouse_Animation,
                        HouseSound_NotEnoughMoney_TrainingSuccessful);

                    if (pMovie_Track) pMediaPlayer->Unload();
                    DialogueEnding();
                    viewparams->bRedrawGameUI = true;
                    if (dword_59117C_teleportx | dword_591178_teleporty |
                        dword_591174_teleportz |
                        dword_591170_teleport_directiony |
                        dword_59116C_teleport_directionx |
                        dword_591168_teleport_speedz) {
                        if (dword_59117C_teleportx) {
                            pParty->vPosition.x = dword_59117C_teleportx;
                            _5B65A8_npcdata_uflags_or_other =
                                dword_59117C_teleportx;
                        }
                        if (dword_591178_teleporty) {
                            pParty->vPosition.y = dword_591178_teleporty;
                            _5B65AC_npcdata_fame_or_other =
                                dword_591178_teleporty;
                        }
                        if (dword_591174_teleportz) {
                            pParty->vPosition.z = dword_591174_teleportz;
                            _5B65B0_npcdata_rep_or_other =
                                dword_591174_teleportz;
                            pParty->uFallStartY = dword_591174_teleportz;
                        }
                        if (dword_591170_teleport_directiony) {
                            pParty->sRotationY =
                                dword_591170_teleport_directiony;
                            _5B65B4_npcdata_loword_house_or_other =
                                dword_591170_teleport_directiony;
                        }
                        if (dword_59116C_teleport_directionx) {
                            pParty->sRotationX =
                                dword_59116C_teleport_directionx;
                            _5B65B8_npcdata_hiword_house_or_other =
                                dword_59116C_teleport_directionx;
                            v38 = dword_591168_teleport_speedz;
                            pParty->uFallSpeed = dword_591168_teleport_speedz;
                            dword_5B65BC = dword_591168_teleport_speedz;
                        } else {
                            v38 = dword_5B65BC;
                        }
                        if (*dword_591164_teleport_map_name != 48) {
                            pGameLoadingUI_ProgressBar->uType =
                                (GUIProgressBar::Type)2;
                            dword_5B65C0 =
                                _5B65A8_npcdata_uflags_or_other |
                                _5B65AC_npcdata_fame_or_other |
                                _5B65B0_npcdata_rep_or_other |
                                _5B65B4_npcdata_loword_house_or_other |
                                _5B65B8_npcdata_hiword_house_or_other | v38;
                            OnMapLeave();
                            Transition_StopSound_Autosave(
                                dword_591164_teleport_map_name,
                                MapStartPoint_Party);
                        }
                    } else {
                        EventProcessor(dword_5C3418, 0, 1, dword_5C341C);
                    }
                    if (!_stricmp(s_SavedMapName.data(), "d05.blv"))
                        pParty->GetPlayingTime() += GameTime::FromDays(4);
                    continue;

                case UIMSG_TransitionWindowCloseBtn:
                    CloseWindowBackground();
                    pMediaPlayer->Unload();
                    DialogueEnding();
                    viewparams->bRedrawGameUI = true;
                    continue;
                case UIMSG_CycleCharacters:
                    uActiveCharacter = CycleCharacter(OS_IfShiftPressed());
                    viewparams->bRedrawGameUI = true;
                    continue;
                case UIMSG_OnTravelByFoot:
                    pMessageQueue_50CBD0->Flush();
                    dword_50CDC8 = 1;
                    sub_42FBDD();
                    // pNPCData4 = (NPCData *)GetTravelTime();
                    pOutdoor->level_filename = pCurrentMapName;
                    if (!engine->IsUnderwater() && pParty->bFlying ||
                        pOutdoor->GetTravelDestination(pParty->vPosition.x,
                                                       pParty->vPosition.y,
                                                       pOut, 20) != 1) {
                        viewparams->bRedrawGameUI = 1;
                        CloseWindowBackground();
                        if (pParty->vPosition.x < -22528)
                            pParty->vPosition.x = -22528;
                        if (pParty->vPosition.x > 22528)
                            pParty->vPosition.x = 22528;
                        if (pParty->vPosition.y < -22528)
                            pParty->vPosition.y = -22528;
                        if (pParty->vPosition.y > 22528)
                            pParty->vPosition.y = 22528;
                        DialogueEnding();
                        current_screen_type = SCREEN_GAME;
                    } else {
                        pParty->field_6E4 = 0;
                        pParty->field_6E0 = 0;
                        CastSpellInfoHelpers::_427D48();
                        DialogueEnding();
                        pEventTimer->Pause();
                        pGameLoadingUI_ProgressBar->Initialize(
                            GUIProgressBar::TYPE_Box);
                        ++pGameLoadingUI_ProgressBar->uProgressMax;
                        SaveGame(1, 0);
                        pGameLoadingUI_ProgressBar->Progress();
                        RestAndHeal(24 * 60 * GetTravelTime());
                        if (pParty->uNumFoodRations) {
                            pParty->RestAndHeal();
                            if (pParty->uNumFoodRations < GetTravelTime()) {
                                pPlayer7 = pParty->pPlayers.data();
                                do {
                                    pPlayer7->SetCondition(1, 0);
                                    ++pPlayer7;
                                } while ((signed int)pPlayer7 <
                                         (signed int)pParty->pHirelings.data());
                                ++pParty->days_played_without_rest;
                            }
                            Party::TakeFood(GetTravelTime());
                        } else {
                            pPlayer8 = pParty->pPlayers.data();
                            do {
                                pPlayer8->SetCondition(1, 0);
                                ++pPlayer8;
                            } while ((signed int)pPlayer8 <
                                     (signed int)pParty->pHirelings.data());
                            ++pParty->days_played_without_rest;
                        }
                        pPaletteManager->ResetNonLocked();
                        pSpriteFrameTable->ResetSomeSpriteFlags();
                        pCurrentMapName = pOut;
                        char pLevelName[32];
                        strcpy(pLevelName, pCurrentMapName.c_str());
                        v41 = strtok(pLevelName, ".");
                        strcpy(pLevelName, v41);
                        Level_LoadEvtAndStr(pLevelName);
                        decal_builder->Reset(0);
                        LoadLevel_InitializeLevelEvt();
                        uLevelMapStatsID = pMapStats->GetMapInfo(pCurrentMapName);

                        bNoNPCHiring = 0;

                        engine->SetUnderwater(
                            Is_out15odm_underwater());

                        if (Is_out15odm_underwater() || (pCurrentMapName == "d47.blv"))
                            bNoNPCHiring = 1;
                        PrepareToLoadODM(1u, (ODMRenderParams *)1);
                        bDialogueUI_InitializeActor_NPC_ID = 0;
                        OnMapLoad();
                        pOutdoor->SetFog();
                        TeleportToStartingPoint(uLevel_StartingPointType);
                        bool bOnWater = false;
                        pParty->vPosition.z = GetTerrainHeightsAroundParty2(
                            pParty->vPosition.x, pParty->vPosition.y, &bOnWater, 0);
                        pParty->uFallStartY = pParty->vPosition.z;
                        engine->_461103_load_level_sub();
                        pEventTimer->Resume();
                        viewparams->bRedrawGameUI = 1;
                        current_screen_type = SCREEN_GAME;
                        pGameLoadingUI_ProgressBar->Release();
                    }
                    viewparams->bRedrawGameUI = 1;
                    continue;
                case UIMSG_CHANGE_LOCATION_ClickCencelBtn:
                    CloseWindowBackground();
                    if (pParty->vPosition.x < -22528)
                        pParty->vPosition.x = -22528;
                    if (pParty->vPosition.x > 22528)
                        pParty->vPosition.x = 22528;
                    if (pParty->vPosition.y < -22528)
                        pParty->vPosition.y = -22528;
                    if (pParty->vPosition.y > 22528)
                        pParty->vPosition.y = 22528;
                    DialogueEnding();
                    current_screen_type = SCREEN_GAME;
                    viewparams->bRedrawGameUI = true;
                    continue;
                case UIMSG_CastSpell_Telekinesis:
                    HEXRAYS_LOWORD(v42) = vis->get_picked_object_zbuf_val();
                    v44 = (unsigned __int16)v42;
                    v45 = PID_TYPE(v44);
                    uNumSeconds = v44;
                    v46 = PID_ID(v44);
                    if (v45 == 3) {
                        v47 = pActors[v46].uAIState == Dead;
                        if (!v47) continue;
                        pSpellInfo = (CastSpellInfo *)pGUIWindow_CastTargetedSpell->ptr_1C;
                        pSpellInfo->uFlags &= ~0x40u;
                        pSpellInfo->uPlayerID_2 = uMessageParam;
                        pSpellInfo->spell_target_pid = v44;
                        pParty->pPlayers[pSpellInfo->uPlayerID].SetRecoveryTime(
                            300);
                        pGUIWindow_CastTargetedSpell->Release();
                        pGUIWindow_CastTargetedSpell = 0;
                        mouse->SetCursorImage("MICON1");
                        game_ui_status_bar_event_string_time_left = 0;
                        _50C9A0_IsEnchantingInProgress = 0;
                        back_to_game();
                        continue;
                    }
                    if (v45 == 2) {
                        v47 = (pObjectList
                                   ->pObjects[pSpriteObjects[v46].uObjectDescID]
                                   .uFlags &
                               0x10) == 0;
                        if (!v47) continue;
                        pSpellInfo = (CastSpellInfo *)
                                         pGUIWindow_CastTargetedSpell->ptr_1C;
                        pSpellInfo->uFlags &= ~0x40u;
                        pSpellInfo->uPlayerID_2 = uMessageParam;
                        pSpellInfo->spell_target_pid = v44;
                        pParty->pPlayers[pSpellInfo->uPlayerID].SetRecoveryTime(
                            300);
                        pGUIWindow_CastTargetedSpell->Release();
                        pGUIWindow_CastTargetedSpell = 0;
                        mouse->SetCursorImage("MICON1");
                        game_ui_status_bar_event_string_time_left = 0;
                        _50C9A0_IsEnchantingInProgress = 0;
                        back_to_game();
                        continue;
                    }
                    if (v45 == 5) {
                        v48 = pLevelDecorations[v46].uEventID == 0;
                    } else {
                        if (v45 != 6) continue;
                        if (uCurrentlyLoadedLevelType != 1) {
                            pODMFace = &pOutdoor->pBModels[v44 >> 9].pFaces[v46 & 0x3F];
                            if (!pODMFace->Clickable() ||
                                !pODMFace->sCogTriggeredID)
                                continue;
                            v44 = uNumSeconds;
                            pSpellInfo =
                                (CastSpellInfo *)pGUIWindow_CastTargetedSpell->ptr_1C;
                            pSpellInfo->uFlags &= ~0x40u;
                            pSpellInfo->uPlayerID_2 = uMessageParam;
                            pSpellInfo->spell_target_pid = v44;
                            pParty->pPlayers[pSpellInfo->uPlayerID].SetRecoveryTime(300);
                            pGUIWindow_CastTargetedSpell->Release();
                            pGUIWindow_CastTargetedSpell = 0;
                            mouse->SetCursorImage("MICON1");
                            game_ui_status_bar_event_string_time_left = 0;
                            _50C9A0_IsEnchantingInProgress = 0;
                            back_to_game();
                            continue;
                        }
                        pBLVFace = &pIndoor->pFaces[v46];
                        if (!pBLVFace->Clickable())
                            continue;
                        v48 = pIndoor->pFaceExtras[pBLVFace->uFaceExtraID]
                                  .uEventID == 0;
                    }
                    if (v48) continue;
                    pSpellInfo =
                        (CastSpellInfo *)pGUIWindow_CastTargetedSpell->ptr_1C;
                    pSpellInfo->uFlags &= ~0x40u;
                    pSpellInfo->uPlayerID_2 = uMessageParam;
                    pSpellInfo->spell_target_pid = v44;
                    pParty->pPlayers[pSpellInfo->uPlayerID].SetRecoveryTime(
                        300);
                    pGUIWindow_CastTargetedSpell->Release();
                    pGUIWindow_CastTargetedSpell = 0;
                    mouse->SetCursorImage("MICON1");
                    game_ui_status_bar_event_string_time_left = 0;
                    _50C9A0_IsEnchantingInProgress = 0;
                    back_to_game();
                    continue;
                case UIMSG_CastSpell_Character_Big_Improvement:  // Preservation
                                                                 // and blessing,
                                                                 // treatment
                                                                 // paralysis,
                                                                 // hand
                                                                 // hammers(individual
                                                                 // upgrade)
                case UIMSG_CastSpell_Character_Small_Improvement:  // Fate, cure
                case UIMSG_HiredNPC_CastSpell:
                    pMessageQueue_50CBD0->Flush();
                    if (_50C9A0_IsEnchantingInProgress) {
                        uActiveCharacter = uMessageParam;
                        viewparams->bRedrawGameUI = 1;
                    } else {
                        if (pGUIWindow_CastTargetedSpell) {
                            pSpellInfo =
                                (CastSpellInfo *)
                                    pGUIWindow_CastTargetedSpell->ptr_1C;
                            switch (uMessage) {
                                case UIMSG_CastSpell_Character_Big_Improvement:
                                    pSpellInfo->uFlags &= ~0x02u;
                                    break;
                                case UIMSG_CastSpell_Character_Small_Improvement:
                                    pSpellInfo->uFlags &= ~0x0100u;
                                    break;
                                case UIMSG_HiredNPC_CastSpell:
                                    pSpellInfo->uFlags &= ~0x0200u;
                                    break;
                            }
                            pSpellInfo->uPlayerID_2 = uMessageParam;
                            pParty->pPlayers[pSpellInfo->uPlayerID]
                                .SetRecoveryTime(300);
                            pGUIWindow_CastTargetedSpell->Release();
                            pGUIWindow_CastTargetedSpell = 0;
                            pEventTimer->Resume();
                            mouse->SetCursorImage("MICON1");
                            game_ui_status_bar_event_string_time_left = 0;
                            _50C9A0_IsEnchantingInProgress = 0;
                        }
                    }
                    continue;

                case UIMSG_BF:
                    __debugbreak();
                    dword_50CDC8 = 1;
                    sub_42FBDD();
                    SaveGame(1, 0);
                    pCurrentMapName = pMapStats->pInfos[uHouse_ExitPic].pFilename;
                    dword_6BE364_game_settings_1 |= GAME_SETTINGS_0001;
                    uGameState = GAME_STATE_CHANGE_LOCATION;
                    // v53 = p2DEvents_minus1_::30[26 * (unsigned
                    // int)ptr_507BC0->ptr_1C];
                    v53 =
                        p2DEvents[(unsigned int)window_SpeakInHouse->ptr_1C - 1]
                            ._quest_related;
                    if (v53 < 0) {
                        v54 = abs(v53) - 1;
                        _5B65B8_npcdata_hiword_house_or_other = 0;
                        dword_5B65BC = 0;
                        v55 = dword_4E4560[v54];
                        _5B65AC_npcdata_fame_or_other = dword_4E4578[v54];
                        v56 = dword_4E4590[v54];
                        v57 = dword_4E45A8[v54];
                        _5B65A8_npcdata_uflags_or_other = v55;
                        _5B65B4_npcdata_loword_house_or_other = v57;
                        _5B65B0_npcdata_rep_or_other = v56;
                        dword_5B65C0 =
                            v55 | _5B65AC_npcdata_fame_or_other | v56 | v57;
                    }
                    HouseDialogPressCloseBtn();
                    pMessageQueue_50CBD0->AddGUIMessage(UIMSG_Escape, 1, 0);
                    continue;

                case UIMSG_OnCastTownPortal:
                    pAudioPlayer->StopChannels(-1, -1);
                    pGUIWindow_CurrentMenu =
                        new GUIWindow_TownPortalBook((char *)uMessageParam);
                    continue;

                case UIMSG_OnCastLloydsBeacon:
                    pAudioPlayer->StopChannels(-1, -1);
                    pGUIWindow_CurrentMenu = new GUIWindow_LloydsBook();
                    continue;

                case UIMSG_LloydsBeacon_FlippingBtn:
                    bRecallingBeacon = uMessageParam;
                    v127 = uMessageParam + 204;
                    pAudioPlayer->PlaySound((SoundID)v127, 0, 0, -1, 0, 0);
                    continue;
                case UIMSG_HintBeaconSlot: {
                    if (!pGUIWindow_CurrentMenu) continue;
                    pPlayer = pPlayers[_506348_current_lloyd_playerid + 1];
                    if (uMessageParam >= pPlayer->vBeacons.size()) {
                        continue;
                    }
                    LloydBeacon *beacon = &pPlayer->vBeacons[uMessageParam];
                    if (bRecallingBeacon) {
                        if (beacon->uBeaconTime) {
                            String v173 = pMapStats->pInfos[pMapStats->sub_410D99_get_map_index(beacon->SaveFileID)].pName;
                            GameUI_StatusBar_Set(localization->FormatString(474, v173.c_str()));  // Recall to %s
                        }
                        continue;
                    }
                    pMapNum = pMapStats->GetMapInfo(pCurrentMapName);
                    String pMapName = "Not in Map Stats";
                    if (pMapNum) {
                        pMapName = pMapStats->pInfos[pMapNum].pName;
                    }

                    if (beacon->uBeaconTime) {
                        GameUI_StatusBar_Set(localization->FormatString(
                            475, pMapName.c_str(),
                            pMapStats->pInfos[pMapStats->sub_410D99_get_map_index(
                                beacon->SaveFileID)].pName.c_str()));  // Set %s over %s
                    } else {
                        GameUI_StatusBar_Set(localization->FormatString(476, pMapName.c_str()));  // Set to %s
                    }
                    continue;
                }
                case UIMSG_CloseAfterInstallBeacon:
                    dword_50CDC8 = 1;
                    pMessageQueue_50CBD0->AddGUIMessage(UIMSG_Escape, 0, 0);
                    continue;
                case UIMSG_InstallBeacon:
                    pPlayer9 = pPlayers[_506348_current_lloyd_playerid + 1];
                    if (!pPlayer9->vBeacons[uMessageParam].uBeaconTime && bRecallingBeacon) {
                        continue;
                    }

                    extern bool _506360_installing_beacon;
                    _506360_installing_beacon = true;

                    pPlayer9->CanCastSpell(uRequiredMana);
                    if (pParty->bTurnBasedModeOn) {
                        v60 = sRecoveryTime;
                        pParty->pTurnBasedPlayerRecoveryTimes[_506348_current_lloyd_playerid] = sRecoveryTime;
                        pPlayer9->SetRecoveryTime(v60);
                        pTurnEngine->ApplyPlayerAction();
                    } else {
                        pPlayer9->SetRecoveryTime(
                            (__int64)(flt_6BE3A4_debug_recmod1 *
                                             (double)sRecoveryTime *
                                             2.133333333333333));
                    }
                    pAudioPlayer->PlaySpellSound(lloyds_beacon_spell_id, 0);
                    if (bRecallingBeacon) {
                        if (pCurrentMapName != pGames_LOD->GetSubNodeName(pPlayer9->vBeacons[uMessageParam].SaveFileID)) {
                            SaveGame(1, 0);
                            OnMapLeave();
                            pCurrentMapName = pGames_LOD->GetSubNodeName(pPlayer9->vBeacons[uMessageParam].SaveFileID);
                            dword_6BE364_game_settings_1 |= GAME_SETTINGS_0001;
                            uGameState = GAME_STATE_CHANGE_LOCATION;
                            _5B65A8_npcdata_uflags_or_other = pPlayer9->vBeacons[uMessageParam].PartyPos_X;
                            _5B65AC_npcdata_fame_or_other = pPlayer9->vBeacons[uMessageParam].PartyPos_Y;
                            _5B65B0_npcdata_rep_or_other = pPlayer9->vBeacons[uMessageParam].PartyPos_Z;
                            _5B65B4_npcdata_loword_house_or_other = pPlayer9->vBeacons[uMessageParam].PartyRot_X;
                            _5B65B8_npcdata_hiword_house_or_other = pPlayer9->vBeacons[uMessageParam].PartyRot_Y;
                            dword_5B65C0 = 1;
                        } else {
                            pParty->vPosition.x = pPlayer9->vBeacons[uMessageParam].PartyPos_X;
                            pParty->vPosition.y = pPlayer9->vBeacons[uMessageParam].PartyPos_Y;
                            pParty->vPosition.z = pPlayer9->vBeacons[uMessageParam].PartyPos_Z;
                            pParty->uFallStartY = pParty->vPosition.z;
                            pParty->sRotationY = pPlayer9->vBeacons[uMessageParam].PartyRot_X;
                            pParty->sRotationX = pPlayer9->vBeacons[uMessageParam].PartyRot_Y;
                        }
                        pMessageQueue_50CBD0->AddGUIMessage(UIMSG_Escape, 1, 0);
                        if (pBooksButtonOverlay != nullptr) {
                            pBooksButtonOverlay->Release();
                            pBooksButtonOverlay = nullptr;
                        }
                        pGUIWindow_CurrentMenu->Release();
                        pGUIWindow_CurrentMenu = 0;
                    } else {
                        pPlayer9->SetBeacon(uMessageParam, lloyds_beacon_spell_level);
                    }
                    continue;
                case UIMSG_ClickTownInTP:
                    if (uMessageParam) {
                        switch (uMessageParam) {
                            case 1:
                                v63 = 208;
                                break;
                            case 2:
                                v63 = 207;
                                break;
                            case 3:
                                v63 = 211;
                                break;
                            case 4:
                                v63 = 209;
                                break;
                            default:
                                if (uMessageParam != 5) {
                                LABEL_486:
                                    SaveGame(1, 0);
                                    v64 =
                                        pMapStats->GetMapInfo(pCurrentMapName);
                                    v65 = uMessageParam;
                                    if (v64 == TownPortalList[uMessageParam]
                                                   .uMapInfoID) {
                                        pParty->vPosition.x =
                                            TownPortalList[v65].pos.x;
                                        pParty->vPosition.y =
                                            TownPortalList[v65].pos.y;
                                        pParty->vPosition.z =
                                            TownPortalList[v65].pos.z;
                                        pParty->uFallStartY =
                                            pParty->vPosition.z;
                                        pParty->sRotationY =
                                            TownPortalList[v65].rot_y;
                                        pParty->sRotationX =
                                            TownPortalList[v65].rot_x;
                                    } else {
                                        SaveGame(1, 0);
                                        OnMapLeave();
                                        dword_6BE364_game_settings_1 |=
                                            GAME_SETTINGS_0001;
                                        uGameState = GAME_STATE_CHANGE_LOCATION;
                                        pCurrentMapName =
                                               pMapStats->pInfos[TownPortalList[uMessageParam].uMapInfoID]
                                                   .pFilename;
                                        dword_5B65C0 = 1;
                                        _5B65A8_npcdata_uflags_or_other =
                                            TownPortalList[uMessageParam].pos.x;
                                        _5B65AC_npcdata_fame_or_other =
                                            TownPortalList[uMessageParam].pos.y;
                                        _5B65B0_npcdata_rep_or_other =
                                            TownPortalList[uMessageParam].pos.z;
                                        v66 =
                                            TownPortalList[uMessageParam].rot_x;
                                        _5B65B4_npcdata_loword_house_or_other =
                                            TownPortalList[uMessageParam].rot_y;
                                        _5B65B8_npcdata_hiword_house_or_other =
                                            v66;
                                        Actor::InitializeActors();
                                    }
                                    //                            v67 =
                                    //                            (char*)pGUIWindow_CurrentMenu->sHint;
                                    //                            if (v67)
                                    //                                *((int
                                    //                                *)v67 +
                                    //                                17) = 1;
                                    //                            else
                                    pParty
                                        ->pPlayers[(unsigned __int8)
                                                       town_portal_caster_id]
                                        .CanCastSpell(0x14u);

                                    pMessageQueue_50CBD0->AddGUIMessage(
                                        UIMSG_Escape, 1, 0);
                                    continue;
                                }
                                v63 = 210;
                                break;
                        }
                    } else {
                        v63 = 206;
                    }
                    if (!(unsigned __int16)_449B57_test_bit(pParty->_quest_bits,
                                                            v63))
                        return;
                    goto LABEL_486;
                case UIMSG_HintTownPortal: {
                    String v69;
                    if (uMessageParam) {
                        switch (uMessageParam) {
                        case 1:
                            v68 = 208;
                            break;
                        case 2:
                            v68 = 207;
                            break;
                        case 3:
                            v68 = 211;
                            break;
                        case 4:
                            v68 = 209;
                            break;
                        default:
                            if (uMessageParam != 5) {
                                if (uMessageParam) {
                                    switch (uMessageParam) {
                                    case 1:
                                        v69 =
                                            pMapStats->pInfos[4].pName;
                                        break;
                                    case 2:
                                        v69 =
                                            pMapStats->pInfos[3].pName;
                                        break;
                                    case 3:
                                        v69 =
                                            pMapStats->pInfos[10].pName;
                                        break;
                                    case 4:
                                        v69 =
                                            pMapStats->pInfos[7].pName;
                                        break;
                                    default:
                                        if (uMessageParam != 5) {
                                            __debugbreak();  // warning
                                                             // C4700:
                                                             // uninitialized
                                                             // local
                                                             // variable
                                                             // 'v200'
                                                             // used
                                            GameUI_StatusBar_Set(
                                                localization
                                                ->FormatString(
                                                    35, v200));
                                            continue;
                                        }
                                        v69 =
                                            pMapStats->pInfos[8].pName;
                                        break;
                                    }
                                } else {
                                    v69 = pMapStats->pInfos[21].pName;
                                }
                                GameUI_StatusBar_Set(
                                    localization->FormatString(35, v69));
                                continue;
                            }
                            v68 = 210;
                            break;
                        }
                    } else {
                        v68 = 206;
                    }
                    if (!(unsigned __int16)_449B57_test_bit(pParty->_quest_bits, v68)) {
                        render->DrawTextureNew(0, 352 / 480.0f, game_ui_statusbar);
                        continue;
                    }
                    // LABEL_506:
                    if (uMessageParam) {
                        switch (uMessageParam) {
                        case 1:
                            v69 = pMapStats->pInfos[4].pName;
                            break;
                        case 2:
                            v69 = pMapStats->pInfos[3].pName;
                            break;
                        case 3:
                            v69 = pMapStats->pInfos[10].pName;
                            break;
                        case 4:
                            v69 = pMapStats->pInfos[7].pName;
                            break;
                        default:
                            if (uMessageParam != 5) {
                                GameUI_StatusBar_Set(
                                    localization->FormatString(35, v200));
                                continue;
                            }
                            v69 = pMapStats->pInfos[8].pName;
                            break;
                        }
                    } else {
                        v69 = pMapStats->pInfos[21].pName;
                    }
                    GameUI_StatusBar_Set(localization->FormatString(35, v69));
                    continue;
                }
                case UIMSG_ShowFinalWindow: {
                    static String
                        final_message;  // static due to GUIWindow_Modal not
                                        // holding a reference and text ptr will
                                        // be destroyed upon exiting scope

                    final_message = StringPrintf("%s\n \n%s\n \n%s", localization->GetString(151),  // Congratulations Adventurer.
                        localization->GetString(118),  // We hope that you've enjoyed playing Might
                                                       // and Magic VII as much as we did making it.
                                                       // We have saved this screen as MM7_WIN.PCX
                                                       // in your MM7 directory. You can print it
                                                       // out as proof of your accomplishment.
                        localization->GetString(167));  // - The Might and Magic VII Development Team.

                    pModalWindow = new GUIWindow_Modal(final_message.c_str(), UIMSG_OnFinalWindowClose);
                    uGameState = GAME_STATE_FINAL_WINDOW;
                    continue;
                }
                case UIMSG_OnFinalWindowClose:
                    __debugbreak();
                    uGameState = GAME_STATE_PLAYING;
                    strcpy((char *)pKeyActionMap->pPressedKeysBuffer, "2");
                    __debugbreak();  // missed break/continue?
                case UIMSG_DD: {
                    __debugbreak();
                    // sprintf(tmp_str.data(), "%s",
                    // pKeyActionMap->pPressedKeysBuffer);
                    FrameTableTxtLine frameTableTxtLine;
                    txt_file_frametable_parser(pKeyActionMap->pPressedKeysBuffer, &frameTableTxtLine);
                    String status_string;
                    if (frameTableTxtLine.uPropCount == 1) {
                        size_t map_index = atoi(frameTableTxtLine.pProperties[0]);
                        if (map_index <= 0 || map_index >= 77) continue;
                        String map_name = pMapStats->pInfos[map_index].pFilename;
                        if (pGames_LOD->GetSubNodeIndex(map_name) < (pGames_LOD->GetSubNodesCount() / 2)) {
                            pCurrentMapName = map_name;
                            dword_6BE364_game_settings_1 |= GAME_SETTINGS_0001;
                            uGameState = GAME_STATE_CHANGE_LOCATION;
                            OnMapLeave();
                            continue;
                        }
                        status_string = StringPrintf("No map found for %s", pMapStats->pInfos[map_index].pName.c_str());
                    } else {
                        if (frameTableTxtLine.uPropCount != 3) continue;
                        int x = atoi(frameTableTxtLine.pProperties[0]);
                        int y = atoi(frameTableTxtLine.pProperties[1]);
                        int z = atoi(frameTableTxtLine.pProperties[2]);
                        if (uCurrentlyLoadedLevelType == LEVEL_Indoor) {
                            if (pIndoor->GetSector(x, y, z)) {
                                pParty->vPosition.x = x;
                                pParty->vPosition.y = y;
                                pParty->vPosition.z = z;
                                pParty->uFallStartY = z;
                                continue;
                            }
                        } else {
                            if ((x > -32768) && (x < 32768) && (y > -32768) && (y < 32768) && (z >= 0) && (z < 10000)) {
                                pParty->vPosition.x = x;
                                pParty->vPosition.y = y;
                                pParty->vPosition.z = z;
                                pParty->uFallStartY = z;
                                continue;
                            }
                        }
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                        status_string = "Can't jump to that location!";
                    }
                    GameUI_StatusBar_OnEvent(status_string, 6);
                    continue;
                }
                case UIMSG_CastQuickSpell: {
                    if (engine->IsUnderwater()) {
                        GameUI_StatusBar_OnEvent(localization->GetString(652));  // "You can not do that while you are // underwater!"
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                        continue;
                    }
                    if (!uActiveCharacter ||
                        (pPlayer2 = pPlayers[uActiveCharacter],
                         pPlayer2->uTimeToRecovery))
                        continue;
                    _42777D_CastSpell_UseWand_ShootArrow(
                        (SPELL_TYPE)pPlayer2->uQuickSpell, uActiveCharacter - 1,
                        0, 0, uActiveCharacter);
                    continue;
                }

                case UIMSG_CastSpell_Monster_Improvement:
                case UIMSG_CastSpell_Shoot_Monster:  // FireBlow, Lightning, Ice
                                                     // Lightning, Swarm,
                    v83 = vis->get_picked_object_zbuf_val();
                    v44 = (unsigned __int16)v83;
                    v84 = v83 >> 16;
                    if (PID_TYPE(v44) != 3 || v84 >= 5120) continue;
                    pSpellInfo = (CastSpellInfo *)pGUIWindow_CastTargetedSpell->ptr_1C;
                    if (uMessage == UIMSG_CastSpell_Shoot_Monster) {
                        pSpellInfo->uFlags &= ~0x08;
                    } else {
                        if (uMessage == UIMSG_CastSpell_Monster_Improvement)
                            pSpellInfo->uFlags &= ~0x0100u;
                        else
                            pSpellInfo->uFlags &= ~0x0200u;
                    }
                    pSpellInfo->uPlayerID_2 = uMessageParam;
                    pSpellInfo->spell_target_pid = v44;
                    pParty->pPlayers[pSpellInfo->uPlayerID].SetRecoveryTime(300);
                    pGUIWindow_CastTargetedSpell->Release();
                    pGUIWindow_CastTargetedSpell = 0;
                    mouse->SetCursorImage("MICON1");
                    game_ui_status_bar_event_string_time_left = 0;
                    _50C9A0_IsEnchantingInProgress = 0;
                    back_to_game();
                    continue;
                case UIMSG_1C:
                    __debugbreak();
                    if (!uActiveCharacter || current_screen_type != SCREEN_GAME)
                        continue;
                    __debugbreak();  // ptr_507BC8 = GUIWindow::Create(0, 0,
                                     // window->GetWidth(), window->GetHeight(),
                                     // WINDOW_68, uMessageParam, 0);
                    current_screen_type = SCREEN_19;
                    pEventTimer->Pause();
                    continue;
                case UIMSG_STEALFROMACTOR:
                    if (!uActiveCharacter) continue;
                    if (!pParty->bTurnBasedModeOn) {
                        if (pActors[uMessageParam].uAIState == 5)
                            pActors[uMessageParam].LootActor();
                        else
                            Actor::StealFrom(uMessageParam);
                        continue;
                    }
                    if (pTurnEngine->turn_stage == TE_WAIT ||
                        pTurnEngine->turn_stage == TE_MOVEMENT)
                        continue;
                    if (!(pTurnEngine->field_18 & TE_HAVE_PENDING_ACTIONS)) {
                        if (pActors[uMessageParam].uAIState == 5)
                            pActors[uMessageParam].LootActor();
                        else
                            Actor::StealFrom(uMessageParam);
                    }
                    continue;

                case UIMSG_Attack:
                    if (!uActiveCharacter) continue;
                    if (!pParty->bTurnBasedModeOn) {
                        Player::_42ECB5_PlayerAttacksActor();
                        continue;
                    }
                    if (pTurnEngine->turn_stage == TE_WAIT ||
                        pTurnEngine->turn_stage == TE_MOVEMENT)
                        continue;
                    if (!(pTurnEngine->field_18 & TE_HAVE_PENDING_ACTIONS))
                        Player::_42ECB5_PlayerAttacksActor();
                    continue;
                case UIMSG_ExitRest:
                    new OnCancel(pButton_RestUI_Exit->uX,
                                 pButton_RestUI_Exit->uY, 0, 0,
                                 (int)pButton_RestUI_Exit,
                                 localization->GetString(81));  // "Exit Rest"
                    continue;
                case UIMSG_Wait5Minutes:
                    if (_506F14_resting_stage == 2) {
                        GameUI_StatusBar_OnEvent(localization->GetString(
                            477));  // "You are already resting!"
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                        continue;
                    }
                    new OnButtonClick2(
                        pButton_RestUI_Wait5Minutes->uX,
                        pButton_RestUI_Wait5Minutes->uY, 0, 0,
                        (int)pButton_RestUI_Wait5Minutes,
                        localization->GetString(238));  // "Wait 5 Minutes"
                    _506F14_resting_stage = 1;
                    _506F18_num_minutes_to_sleep = 5;
                    continue;
                case UIMSG_Wait1Hour:
                    if (_506F14_resting_stage == 2) {
                        GameUI_StatusBar_OnEvent(localization->GetString(
                            477));  // "You are already resting!"
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                        continue;
                    }
                    new OnButtonClick2(
                        pButton_RestUI_Wait1Hour->uX,
                        pButton_RestUI_Wait1Hour->uY, 0, 0,
                        (int)pButton_RestUI_Wait1Hour,
                        localization->GetString(239));  // "Wait 1 Hour"
                    _506F14_resting_stage = 1;
                    _506F18_num_minutes_to_sleep = 60;
                    continue;
                case UIMSG_RentRoom:
                    _506F14_resting_stage = 2;

                    pGUIWindow_CurrentMenu = new GUIWindow_Rest();

                    v86 =
                        60 * (_494820_training_time(pParty->uCurrentHour) + 1) -
                        pParty->uCurrentMinute;
                    _506F18_num_minutes_to_sleep = v86;
                    if (uMessageParam == 111 || uMessageParam == 114 ||
                        uMessageParam == 116)  // 107 = Emerald Isle tavern
                        _506F18_num_minutes_to_sleep = v86 + 12 * 60;
                    _506F14_resting_stage = 2;
                    pParty->RestAndHeal();
                    pParty->days_played_without_rest = 0;
                    pParty->pPlayers[3].SetAsleep(GameTime(1));
                    pParty->pPlayers[2].SetAsleep(GameTime(1));
                    pParty->pPlayers[1].SetAsleep(GameTime(1));
                    pParty->pPlayers[0].SetAsleep(GameTime(1));
                    continue;
                case UIMSG_RestWindow:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME) continue;
                    if (CheckActors_proximity()) {
                        if (pParty->bTurnBasedModeOn) {
                            GameUI_StatusBar_OnEvent(localization->GetString(478));  // "You can't rest in turn-based mode!"
                            continue;
                        }
                        v88 = localization->GetString(
                            480);  // "There are hostile enemies near!"
                        if (pParty->uFlags & 0x88)
                            v88 = localization->GetString(
                                479);  // "You can't rest here!"
                        GameUI_StatusBar_OnEvent(v88);
                        if (!uActiveCharacter) continue;
                        pPlayers[uActiveCharacter]->PlaySound((PlayerSpeech)13,
                                                              0);
                        continue;
                    }
                    if (pParty->bTurnBasedModeOn) {
                        GameUI_StatusBar_OnEvent(localization->GetString(478));  // "You can't rest in turn-based mode!"
                        continue;
                    }
                    if (!(pParty->uFlags & 0x88)) {
                        pGUIWindow_CurrentMenu = new GUIWindow_Rest();
                        continue;
                    }
                    if (pParty->bTurnBasedModeOn) {
                        GameUI_StatusBar_OnEvent(localization->GetString(478));  // "You can't rest in turn-based mode!"
                        continue;
                    }
                    v88 = localization->GetString(
                        480);  // "There are hostile enemies near!"
                    if (pParty->uFlags & 0x88)
                        v88 = localization->GetString(
                            479);  // "You can't rest here!"
                    GameUI_StatusBar_OnEvent(v88);
                    if (!uActiveCharacter) continue;
                    pPlayers[uActiveCharacter]->PlaySound(SPEECH_CantRestHere,
                                                          0);
                    continue;
                case UIMSG_Rest8Hour:
                    if (_506F14_resting_stage != 0) {
                        GameUI_StatusBar_OnEvent(localization->GetString(
                            477));  // "You are already resting!"
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                        continue;
                    }
                    if (pParty->uNumFoodRations < uRestUI_FoodRequiredToRest) {
                        GameUI_StatusBar_OnEvent(localization->GetString(482));  // "You don't have enough food to rest"
                        if (uActiveCharacter &&
                            pPlayers[uActiveCharacter]->CanAct())
                            pPlayers[uActiveCharacter]->PlaySound(SPEECH_108,
                                                                  0);
                    } else {
                        pParty->pPlayers[3].conditions_times[Condition_Sleep] =
                            pParty->GetPlayingTime();
                        pParty->pPlayers[2].conditions_times[Condition_Sleep] =
                            pParty->GetPlayingTime();
                        pParty->pPlayers[1].conditions_times[Condition_Sleep] =
                            pParty->GetPlayingTime();
                        pParty->pPlayers[0].conditions_times[Condition_Sleep] =
                            pParty->GetPlayingTime();
                        v90 = pMapStats->GetMapInfo(pCurrentMapName);
                        if (!v90)
                            v90 = rand() % (signed int)pMapStats->uNumMaps + 1;
                        pMapInfo = &pMapStats->pInfos[v90];
                        if (rand() % 100 + 1 <= pMapInfo->Encounter_percent) {
                            v91 = rand() % 100;
                            v92 = pMapInfo->EncM1percent;
                            v93 = v91 + 1;
                            if (v93 > v92)
                                pNPCData4 =
                                    (NPCData *)((v93 >
                                                 v92 + pMapInfo->EncM2percent) +
                                                2);
                            else
                                pNPCData4 = (NPCData *)1;
                            if (!_45063B_spawn_some_monster(pMapInfo,
                                                            (int)pNPCData4))
                                pNPCData4 = 0;
                            if (pNPCData4) {
                                pPlayerNum = rand() % 4;
                                pParty->pPlayers[pPlayerNum]
                                    .conditions_times[Condition_Sleep]
                                    .Reset();
                                v95 = rand();
                                Rest(v95 % 6 + 60);
                                _506F18_num_minutes_to_sleep = 0;
                                _506F14_resting_stage = 0;

                                pMessageQueue_50CBD0->AddGUIMessage(
                                    UIMSG_Escape, 0, 0);
                                GameUI_StatusBar_OnEvent(
                                    localization->GetString(
                                        481));  // "Encounter!"
                                pAudioPlayer->PlaySound(SOUND_encounter, 0, 0,
                                                        -1, 0, 0);
                                continue;
                            }
                        }
                        Party::TakeFood(uRestUI_FoodRequiredToRest);
                        _506F18_num_minutes_to_sleep = 480;
                        _506F14_resting_stage = 2;
                        pParty->RestAndHeal();
                        pParty->days_played_without_rest = 0;
                        pParty->pPlayers[3].SetAsleep(GameTime(1));
                        pParty->pPlayers[2].SetAsleep(GameTime(1));
                        pParty->pPlayers[1].SetAsleep(GameTime(1));
                        pParty->pPlayers[0].SetAsleep(GameTime(1));
                    }
                    continue;
                case UIMSG_AlreadyResting:
                    if (_506F14_resting_stage == 2) {
                        GameUI_StatusBar_OnEvent(localization->GetString(
                            477));  // "You are already resting!"
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                        continue;
                    }
                    new OnButtonClick2(
                        pButton_RestUI_WaitUntilDawn->uX,
                        pButton_RestUI_WaitUntilDawn->uY, 0, 0,
                        (int)pButton_RestUI_WaitUntilDawn,
                        localization->GetString(237));  // "Wait until Dawn"
                    v97 = _494820_training_time(pParty->uCurrentHour);
                    _506F14_resting_stage = 1;
                    _506F18_num_minutes_to_sleep =
                        60 * v97 - pParty->uCurrentMinute;
                    continue;

                case UIMSG_HintSelectRemoveQuickSpellBtn: {
                    if (quick_spell_at_page && byte_506550) {
                        GameUI_StatusBar_Set(localization->FormatString(
                            483,
                            pSpellStats
                                ->pInfos[quick_spell_at_page +
                                         11 * pPlayers[uActiveCharacter]
                                                  ->lastOpenedSpellbookPage]
                                .pName));
                    } else {
                        if (pPlayers[uActiveCharacter]->uQuickSpell)
                            GameUI_StatusBar_Set(localization->GetString(
                                584));  // "Click here to remove your Quick
                                        // Spell"
                        else
                            GameUI_StatusBar_Set(localization->GetString(
                                484));  // "Select a spell then click here to
                                        // set a QuickSpell"
                    }
                    continue;
                }

                case UIMSG_SPellbook_ShowHightlightedSpellInfo: {
                    if (!uActiveCharacter)  // || (uNumSeconds = (unsigned
                                            // int)pPlayers[uActiveCharacter],!*(char
                                            // *)(uNumSeconds + 11 * *(char
                                            // *)(uNumSeconds + 6734) +
                                            // uMessageParam + 402)))
                        continue;  // this used to check if player had the spell
                                   // activated - no longer rquired here ??

                    if (sub_4637E0_is_there_popup_onscreen())
                        dword_507B00_spell_info_to_draw_in_popup =
                            uMessageParam + 1;
                    v98 = pPlayers[uActiveCharacter]
                              ->lastOpenedSpellbookPage;  //  *(char
                                                          //  *)(uNumSeconds +
                                                          //  6734);
                    if (quick_spell_at_page - 1 == uMessageParam) {
                        GameUI_StatusBar_Set(localization->FormatString(
                            485,
                            pSpellStats->pInfos[uMessageParam + 11 * v98 + 1]
                                .pName));
                    } else {
                        GameUI_StatusBar_Set(localization->FormatString(
                            486,
                            pSpellStats->pInfos[uMessageParam + 11 * v98 + 1]
                                .pName));
                    }
                    continue;
                }

                case UIMSG_ClickInstallRemoveQuickSpellBtn: {
                    new OnButtonClick2(pBtn_InstallRemoveSpell->uX,
                                       pBtn_InstallRemoveSpell->uY, 0, 0,
                                       (int)pBtn_InstallRemoveSpell);
                    if (!uActiveCharacter) continue;
                    pPlayer10 = pPlayers[uActiveCharacter];
                    if (!byte_506550 || !quick_spell_at_page) {
                        pPlayer10->uQuickSpell = 0;
                        quick_spell_at_page = 0;
                        pAudioPlayer->PlaySound(SOUND_fizzle, 0, 0, -1, 0, 0);
                        continue;
                    }
                    pPlayers[uActiveCharacter]->uQuickSpell =
                        quick_spell_at_page +
                        11 *
                            pPlayers[uActiveCharacter]->lastOpenedSpellbookPage;
                    AA1058_PartyQuickSpellSound[uActiveCharacter - 1]
                        .AddPartySpellSound(
                            pPlayers[uActiveCharacter]->uQuickSpell,
                            uActiveCharacter);
                    if (uActiveCharacter) pPlayer10->PlaySound(SPEECH_12, 0);
                    byte_506550 = 0;
                    continue;
                }

                case UIMSG_SpellBook_PressTab:  //перелистывание страниц
                                                //клавишей Tab
                {
                    if (!uActiveCharacter) continue;
                    int skill_count = 0;
                    uAction = 0;
                    for (uint i = 0; i < 9; i++) {
                        if (pPlayers[uActiveCharacter]->pActiveSkills[PLAYER_SKILL_FIRE + i] ||
                            engine->config->debug_all_magic) {
                            if (pPlayers[uActiveCharacter]->lastOpenedSpellbookPage == i)
                                uAction = skill_count;
                            v217[skill_count++] = i;
                        }
                    }
                    if (!skill_count) {  //нет скиллов
                        pAudioPlayer->PlaySound(
                            (SoundID)(rand() % 2 + SOUND_TurnPageU), 0, 0, -1, 0, 0);
                    } else {
                        if (OS_IfShiftPressed()) {
                            --uAction;
                            if (uAction < 0)
                                uAction = skill_count - 1;
                        } else {
                            ++uAction;
                            if (uAction >= skill_count)
                                uAction = 0;
                        }
                        ((GUIWindow_Spellbook *)pGUIWindow_CurrentMenu)->OpenSpellbookPage(v217[uAction]);
                    }
                    continue;
                }
                case UIMSG_OpenSpellbookPage:
                    if (pTurnEngine->turn_stage == TE_MOVEMENT ||
                        !uActiveCharacter ||
                        uMessageParam ==
                            pPlayers[uActiveCharacter]->lastOpenedSpellbookPage)
                        continue;
                    ((GUIWindow_Spellbook *)pGUIWindow_CurrentMenu)->OpenSpellbookPage(uMessageParam);
                    continue;
                case UIMSG_SelectSpell: {
                    if (pTurnEngine->turn_stage == TE_MOVEMENT) continue;
                    if (!uActiveCharacter) continue;

                    //  uNumSeconds = (unsigned int)pPlayers[uActiveCharacter];
                    Player *player = pPlayers[uActiveCharacter];
                    if (player->spellbook.pChapters[player->lastOpenedSpellbookPage].bIsSpellAvailable[uMessageParam]
                        || engine->config->debug_all_magic) {
                        if (quick_spell_at_page - 1 == uMessageParam) {
                            pGUIWindow_CurrentMenu->Release();  // spellbook close
                            pEventTimer->Resume();
                            viewparams->bRedrawGameUI = 1;
                            current_screen_type = SCREEN_GAME;
                            v103 = quick_spell_at_page + 11 * player->lastOpenedSpellbookPage;
                            /*if ( dword_50C9E8 < 40 )
                            {
                            dword_50C9EC[3 * dword_50C9E8] =
                            UIMSG_CastSpellFromBook; dword_50C9EC[3 *
                            dword_50C9E8 + 1] = v103; dword_50C9EC[3 *
                            dword_50C9E8 + 2] = uActiveCharacter - 1;
                            ++dword_50C9E8;
                            }*/
                            pMessageQueue_50C9E8->AddGUIMessage(
                                UIMSG_CastSpellFromBook, v103,
                                uActiveCharacter - 1);
                            //  pMessageQueue_50CBD0->AddGUIMessage(UIMSG_CastSpellFromBook,
                            //  v103, uActiveCharacter - 1);
                        } else {
                            byte_506550 = 1;
                            quick_spell_at_page = uMessageParam + 1;
                        }
                    }
                    continue;
                }

                case UIMSG_CastSpellFromBook:
                    if (pTurnEngine->turn_stage != TE_MOVEMENT)
                        _42777D_CastSpell_UseWand_ShootArrow(
                            (SPELL_TYPE)uMessageParam, v199, 0, 0, 0);
                    continue;

                case UIMSG_SpellScrollUse:
                    __debugbreak();
                    if (pTurnEngine->turn_stage != TE_MOVEMENT)
                        _42777D_CastSpell_UseWand_ShootArrow(
                            (SPELL_TYPE)uMessageParam, v199, 133, 1, 0);
                    continue;
                case UIMSG_SpellBookWindow:
                    if (pTurnEngine->turn_stage == TE_MOVEMENT) continue;
                    if (engine->IsUnderwater()) {
                        GameUI_StatusBar_OnEvent(localization->GetString(652));  // "You can not do that while you are underwater!"
                        pAudioPlayer->PlaySound(SOUND_error, 0, 0, -1, 0, 0);
                    } else {
                        pMessageQueue_50CBD0->Flush();
                        if (uActiveCharacter &&
                            !pPlayers[uActiveCharacter]->uTimeToRecovery) {
                            if (current_screen_type == SCREEN_GAME) {
                                new OnButtonClick2(476, 450, 0, 0, (int)pBtn_CastSpell);
                                pGUIWindow_CurrentMenu = new GUIWindow_Spellbook();
                                continue;
                            }
                            if (current_screen_type != SCREEN_REST &&
                                current_screen_type != SCREEN_CHARACTERS &&
                                (current_screen_type <= SCREEN_63 ||
                                 current_screen_type > SCREEN_67)) {
                                pGUIWindow_CurrentMenu->Release();
                                new OnButtonClick2(476, 450, 0, 0,
                                                   (int)pBtn_CastSpell);
                                pGUIWindow_CurrentMenu =
                                    new GUIWindow_Spellbook();
                                continue;
                            }
                        }
                    }
                    continue;
                case UIMSG_QuickReference:
                    pMessageQueue_50CBD0->Flush();
                    if (current_screen_type != SCREEN_GAME)
                        pGUIWindow_CurrentMenu->Release();

                    new OnButtonClick2(0x230u, 0x1C2u, 0, 0,
                                       (int)pBtn_QuickReference);
                    viewparams->bRedrawGameUI = true;

                    pGUIWindow_CurrentMenu = new GUIWindow_QuickReference();
                    continue;
                case UIMSG_GameMenuButton:
                    if (current_screen_type != SCREEN_GAME) {
                        pGUIWindow_CurrentMenu->Release();
                        pEventTimer->Resume();
                        current_screen_type = SCREEN_GAME;
                        viewparams->bRedrawGameUI = 1;
                    }

                    if (gamma_preview_image) {
                        gamma_preview_image->Release();
                        gamma_preview_image = nullptr;
                    }
                    render->SaveScreenshot("gamma.pcx", 155, 117);
                    gamma_preview_image =
                        assets->GetImage_PCXFromFile("gamma.pcx");

                    new OnButtonClick(0x25Au, 0x1C2u, 0, 0,
                                      (int)pBtn_GameSettings);
                    // LABEL_453:
                    /*if ( (signed int)pMessageQueue_50CBD0->uNumMessages >= 40
                    ) continue;
                    pMessageQueue_50CBD0->pMessages[pMessageQueue_50CBD0->uNumMessages].eType
                    = UIMSG_Escape;
                    //goto LABEL_770;
                    pMessageQueue_50CBD0->pMessages[pMessageQueue_50CBD0->uNumMessages].param
                    = 0;
                    *(&pMessageQueue_50CBD0->uNumMessages + 3 *
                    pMessageQueue_50CBD0->uNumMessages + 3) = 0;
                    ++pMessageQueue_50CBD0->uNumMessages;*/
                    pMessageQueue_50CBD0->AddGUIMessage(UIMSG_Escape, 0, 0);
                    continue;
                case UIMSG_ClickAwardScrollBar: {
                    books_page_number = 1;
                    Point pt = mouse->GetCursorPos();
                    if (pt.y > 178) books_page_number = -1;
                    continue;
                }
                case UIMSG_ClickAwardsUpBtn:
                    new OnButtonClick3(pBtn_Up->uX, pBtn_Up->uY, 0, 0,
                                       (int)pBtn_Up);
                    BtnUp_flag = 1;
                    continue;
                case UIMSG_ClickAwardsDownBtn:
                    new OnButtonClick3(pBtn_Down->uX, pBtn_Down->uY, 0, 0,
                                       (int)pBtn_Down);
                    BtnDown_flag = 1;
                    continue;
                case UIMSG_ChangeDetaliz:
                    ((GUIWindow_CharacterRecord *)pGUIWindow_CurrentMenu)
                        ->ToggleRingsOverlay();
                    continue;
                case UIMSG_ClickPaperdoll:
                    OnPaperdollLeftClick();
                    continue;
                case UIMSG_SkillUp:
                    pPlayer4 = pPlayers[uActiveCharacter];
                    v105 = (int)&pPlayer4->pActiveSkills[uMessageParam];
                    HEXRAYS_LOWORD(v2) = *(short *)v105;
                    uNumSeconds = v2;
                    if (pPlayer4->uSkillPoints < (v2 & 0x3F) + 1) {
                        v87 = localization->GetString(
                            488);  // "You don't have enough skill points!"
                    } else {
                        if ((uNumSeconds & 0x3F) < 0x3C) {
                            *(short *)v105 = uNumSeconds + 1;
                            pPlayer4->uSkillPoints -=
                                pPlayer4->pActiveSkills[uMessageParam] & 0x3F;
                            pPlayer4->PlaySound(SPEECH_14, 0);
                            pAudioPlayer->PlaySound((SoundID)SOUND_quest, 0, 0,
                                                    -1, 0, 0);
                            continue;
                        }
                        v87 = localization->GetString(
                            487);  // "You have already mastered this skill!"
                    }
                    GameUI_StatusBar_OnEvent(v87);
                    continue;
                case UIMSG_ClickStatsBtn:
                    ((GUIWindow_CharacterRecord *)pGUIWindow_CurrentMenu)
                        ->ShowStatsTab();
                    continue;
                case UIMSG_ClickSkillsBtn:
                    ((GUIWindow_CharacterRecord *)pGUIWindow_CurrentMenu)
                        ->ShowSkillsTab();
                    continue;
                case UIMSG_ClickInventoryBtn:
                    ((GUIWindow_CharacterRecord *)pGUIWindow_CurrentMenu)
                        ->ShowInventoryTab();
                    continue;
                case UIMSG_ClickAwardsBtn:
                    ((GUIWindow_CharacterRecord *)pGUIWindow_CurrentMenu)
                        ->ShowAwardsTab();
                    continue;
                case UIMSG_ClickExitCharacterWindowBtn:
                    new OnCancel2(pCharacterScreen_ExitBtn->uX,
                                  pCharacterScreen_ExitBtn->uY, 0, 0,
                                  (int)pCharacterScreen_ExitBtn);
                    continue;
                case UIMSG_ClickBooksBtn:
                    switch (uMessageParam) {
                        case 11:  // Page UP
                            BtnUp_flag = 1;
                            pButton = pBtn_Book_2;
                            break;
                        case 10:  // Page DOWN
                            BtnDown_flag = 1;
                            pButton = pBtn_Book_1;
                            break;
                        case 0:  // Zoom plus
                            pButton = pBtn_Book_1;
                            BtnDown_flag = 1;
                            break;
                        case 1:  // Zoom minus
                            pButton = pBtn_Book_2;
                            BtnUp_flag = 1;
                            break;
                        case 2:  // Potions
                            Book_PageBtn3_flag = 1;
                            if (dword_506364) continue;
                            pButton = pBtn_Book_3;
                            break;
                        case 3:  // fountains
                            Book_PageBtn4_flag = 1;
                            if (dword_506364) continue;
                            pButton = pBtn_Book_4;
                            break;
                        case 4:  // obelisks
                            Book_PageBtn5_flag =
                                1;  // Autonotes_Obelisks_page_flag
                            if (dword_506364) continue;
                            pButton = pBtn_Book_5;
                            break;
                        case 5:                      // seer
                            Book_PageBtn6_flag = 1;  // Autonotes_Seer_page_flag
                            if (dword_506364) continue;
                            pButton = pBtn_Book_6;
                            break;
                        case 6:  // misc
                            pButton = pBtn_Autonotes_Misc;
                            Autonotes_Misc_page_flag = 1;
                            break;
                        case 7:  // Instructors
                            pButton = pBtn_Autonotes_Instructors;
                            Autonotes_Instructors_page_flag = 1;
                            break;
                        default:
                            continue;
                    }
                    new OnButtonClick(pButton->uX, pButton->uY, 0, 0,
                                      (int)pButton, String(), false);
                    continue;
                case UIMSG_SelectCharacter:
                    pMessageQueue_50CBD0->Flush();
                    GameUI_OnPlayerPortraitLeftClick(uMessageParam);
                    continue;
                case UIMSG_ShowStatus_Funds: {
                    GameUI_StatusBar_Set(localization->FormatString(
                        489, pParty->uNumGold + pParty->uNumGoldInBank,
                        pParty->uNumGoldInBank));  // You have %d total gold, %d in
                                                   // the Bank
                    continue;
                }
                case UIMSG_ShowStatus_DateTime:
                    currHour = pParty->uCurrentHour;
                    uNumSeconds = 1;
                    if (pParty->uCurrentHour > 12) {
                        if (pParty->uCurrentHour >= 24) uNumSeconds = 0;
                        currHour = (currHour - 12);
                    } else {
                        if (pParty->uCurrentHour < 12)  // 12:00 is PM
                            uNumSeconds = 0;
                        if (pParty->uCurrentHour == 0) currHour = 12;
                    }
                    GameUI_StatusBar_Set(StringPrintf(
                        "%d:%02d%s %s %d %s %d", currHour,
                        pParty->uCurrentMinute,
                        localization->GetAmPm(uNumSeconds),
                        localization->GetDayName(pParty->uCurrentDayOfMonth %
                                                 7),
                        7 * pParty->uCurrentMonthWeek +
                            pParty->uCurrentDayOfMonth % 7 + 1,
                        localization->GetMonthName(pParty->uCurrentMonth),
                        pParty->uCurrentYear));
                    continue;

                case UIMSG_ShowStatus_Food: {
                    GameUI_StatusBar_Set(localization->FormatString(
                        501, pParty->uNumFoodRations));  // You have %lu food
                    continue;
                }

                case UIMSG_ShowStatus_Player: {
                    pPlayer5 = pPlayers[uMessageParam];

                    auto status = localization->FormatString(
                        429, pPlayer5->pName,
                        localization->GetClassName(
                            pPlayer5->classType));  // %s the %s
                    status += ": ";
                    status += localization->GetCharacterConditionName(
                        pPlayer5->GetMajorConditionIdx());
                    GameUI_StatusBar_Set(status);

                    mouse->uPointingObjectID =
                        PID(OBJECT_Player,
                            (unsigned char)(8 * uMessageParam - 8) | 4);
                    continue;
                }

                case UIMSG_ShowStatus_ManaHP: {
                    GameUI_StatusBar_Set(
                        StringPrintf("%d / %d %s    %d / %d %s",
                                     pPlayers[uMessageParam]->GetHealth(),
                                     pPlayers[uMessageParam]->GetMaxHealth(),
                                     localization->GetString(108),
                                     pPlayers[uMessageParam]->GetMana(),
                                     pPlayers[uMessageParam]->GetMaxMana(),
                                     localization->GetString(212)));
                    continue;
                }

                case UIMSG_CHEST_ClickItem:
                    if (current_screen_type == SCREEN_CHEST_INVENTORY) {
                        pPlayers[uActiveCharacter]->OnInventoryLeftClick();
                        continue;
                    }
                    Chest::OnChestLeftClick();
                    continue;
                case UIMSG_InventoryLeftClick:
                    pPlayers[uActiveCharacter]->OnInventoryLeftClick();
                    continue;
                case UIMSG_MouseLeftClickInGame:
                    pMessageQueue_50CBD0->Flush();
                    pMessageQueue_50CBD0->AddGUIMessage(
                        UIMSG_MouseLeftClickInScreen, 0, 0);
                    continue;
                case UIMSG_MouseLeftClickInScreen:  // срабатывает при нажатии на
                                                    // правую кнопку мыши после
                                                    // UIMSG_MouseLeftClickInGame
                    pMessageQueue_50CBD0->Flush();
                    engine->OnGameViewportClick();
                    continue;
                case UIMSG_F:  // what event?
                    __debugbreak();
                    pButton2 = (GUIButton *)(unsigned __int16)vis->get_picked_object_zbuf_val();
                    __debugbreak();  // GUIWindow::Create(0, 0, 0, 0, WINDOW_F, (int)pButton2, 0);
                    continue;
                case UIMSG_54:  // what event?
                    __debugbreak();
                    pButton2 = (GUIButton *)uMessageParam;
                    __debugbreak();  // GUIWindow::Create(0, 0, 0, 0, WINDOW_22, (int)pButton2, 0);
                    continue;
                case UIMSG_Game_Action:
                    pMessageQueue_50CBD0->Flush();
                    // if currently in a chest
                    if (current_screen_type == SCREEN_CHEST) {
                        Chest::GrabItem(OS_IfCtrlPressed());
                    } else {
                        OnPressSpace();
                    }
                    continue;
                case UIMSG_ClickZoomOutBtn:
                    if (current_screen_type) continue;
                    pParty->uFlags |= 2u;
                    new OnButtonClick2(519, 136, 0, 0, (int)pBtn_ZoomOut);
                    uNumSeconds = 131072;
                    v118 = 2 * viewparams->uMinimapZoom;
                    ++viewparams->field_28;
                    viewparams->uMinimapZoom *= 2;
                    if (uCurrentlyLoadedLevelType != LEVEL_Outdoor) {
                        if (v118 > 4096) {
                            viewparams->uMinimapZoom = 4096;
                            viewparams->field_28 = 12;
                        }
                        continue;
                    }
                    v119 = 2048;
                    if ((signed int)v118 <= 2048) {
                        _576E2C_current_minimap_zoom = v118;
                        dword_576E28 = viewparams->field_28;
                        break;
                    }
                    viewparams->field_28 = 11;
                    viewparams->uMinimapZoom = v119;
                    _576E2C_current_minimap_zoom = v119;
                    dword_576E28 = viewparams->field_28;
                    break;
                case UIMSG_ClickZoomInBtn:
                    if (current_screen_type) continue;
                    pParty->uFlags |= 2u;
                    new OnButtonClick2(574, 136, 0, 0, (int)pBtn_ZoomIn);
                    uNumSeconds = 32768;
                    v118 = (unsigned __int64)((signed __int64)(signed int)
                                                  viewparams->uMinimapZoom
                                              << 15) >>
                           16;
                    --viewparams->field_28;
                    viewparams->uMinimapZoom =
                        (unsigned __int64)((signed __int64)(signed int)
                                               viewparams->uMinimapZoom
                                           << 15) >>
                        16;
                    if (uCurrentlyLoadedLevelType == LEVEL_Outdoor) {
                        v119 = 512;
                        if (v118 < 512) {
                            viewparams->field_28 = 9;
                            v118 = v119;
                            viewparams->uMinimapZoom = v119;
                        }
                        _576E2C_current_minimap_zoom = v118;
                        dword_576E28 = viewparams->field_28;
                    } else {
                        if ((signed int)v118 < 256) {
                            viewparams->uMinimapZoom = 256;
                            viewparams->field_28 = 8;
                        }
                    }
                default:
                    continue;
            }
        }
    }

    pMessageQueue_50CBD0 = pMessageQueue_50C9E8;
    pMessageQueue_50C9E8->Clear();

    if (dword_50C9DC) {
        pMessageQueue_50CBD0->AddGUIMessage((UIMessageType)dword_50C9DC,
                                            (int)ptr_50C9E0, 0);
        dword_50C9DC = 0;
    } else {
        if (_50C9D0_AfterEnchClickEventId > 0) {
            _50C9D8_AfterEnchClickEventTimeout -= pEventTimer->uTimeElapsed;
            if (_50C9D8_AfterEnchClickEventTimeout <= 0) {
                pMessageQueue_50CBD0->AddGUIMessage(
                    (UIMessageType)_50C9D0_AfterEnchClickEventId,
                    _50C9D4_AfterEnchClickEventSecondParam, 0);
                _50C9D0_AfterEnchClickEventId = 0;
                _50C9D4_AfterEnchClickEventSecondParam = 0;
                _50C9D8_AfterEnchClickEventTimeout = 0;
            }
        }
    }
    CastSpellInfoHelpers::_427E01_cast_spell();
}

//----- (0046A14B) --------------------------------------------------------
void Game::OnPressSpace() {
    engine->PickKeyboard(Keyboard::IsKeyBeingHeld(VK_CONTROL), &vis_sprite_filter_3, &vis_door_filter);
    int pid = vis->get_picked_object_zbuf_val();
    if (pid != -1)
        DoInteractionWithTopmostZObject(pid & 0xFFFF, PID_ID(pid));
}

void Game::GameLoop() {
    const char *pLocationName;  // [sp-4h] [bp-68h]@74
    bool bLoading;              // [sp+10h] [bp-54h]@1
    signed int v16;             // [sp+14h] [bp-50h]@8
    char Source[64];            // [sp+44h] [bp-20h]@76

    bLoading = sCurrentMenuID == MENU_LoadingProcInMainMenu;
    SetCurrentMenuID((MENU_STATE)-1);
    if (bLoading) {
        pParty->Reset();
        uGameState = GAME_STATE_PLAYING;
        LoadGame(uLoadGameUI_SelectedSlot);
    }

    extern bool use_music_folder;
    GameUI_LoadPlayerPortraintsAndVoices();
    pIcons_LOD->_inlined_sub1();
    pAudioPlayer->SetMusicVolume(engine->config->music_level);

    while (2) {
        v16 = 1;
        pMessageQueue_50CBD0->Flush();

        pPartyActionQueue->uNumActions = 0;
        if (pParty->bTurnBasedModeOn) {
            pTurnEngine->End(false);
            pParty->bTurnBasedModeOn = false;
        }
        DoPrepareWorld(bLoading, 1);
        pEventTimer->Resume();
        dword_6BE364_game_settings_1 |=
            GAME_SETTINGS_0080_SKIP_USER_INPUT_THIS_FRAME;
        // uGame_if_0_else_ui_id__11_save__else_load__8_drawSpellInfoPopup__22_final_window__26_keymapOptions__2_options__28_videoOptions
        // = 0;
        current_screen_type = SCREEN_GAME;

        // if ( render->pRenderD3D )
        vis->_4C1A02();

        bool game_finished = false;
        do {
            OS_PeekMessageLoop();
            if (dword_6BE364_game_settings_1 & GAME_SETTINGS_APP_INACTIVE) {
                OS_WaitMessage();
                // continue;
            }

            engine->_44EEA7();
            GameUI_WritePointedObjectStatusString();
            keyboard->ProcessInputActions();
            EventLoop();
            if (pArcomageGame->bGameInProgress) {
                ArcomageGame::Loop();
                render->Present();
                continue;
            }

            pMediaPlayer->HouseMovieLoop();

            pEventTimer->Update();
            pMiscTimer->Update();

            OnTimer(0);
            GameUI_StatusBar_Update();
            if (pMiscTimer->bPaused && !pEventTimer->bPaused)
                pMiscTimer->Resume();
            if (pEventTimer->bTackGameTime && !pParty->bTurnBasedModeOn)
                pEventTimer->bTackGameTime = 0;
            if (!pEventTimer->bPaused && uGameState == GAME_STATE_PLAYING) {
                if (!pEventTimer->bTackGameTime)
                    _494035_timed_effects__water_walking_damage__etc();

                if (dword_6BE364_game_settings_1 & GAME_SETTINGS_0001) {
                    dword_6BE364_game_settings_1 &= ~GAME_SETTINGS_0001;
                } else {
                    Actor::UpdateActorAI();
                    UpdateUserInput_and_MapSpecificStuff();
                }
            }
            if (v16) {
                v16 = 0;
                viewparams->bRedrawGameUI = true;
            }
            pAudioPlayer->UpdateSounds();
            if (uGameState == GAME_STATE_PLAYING) {
                engine->Draw();
                continue;
            }
            if (uGameState == GAME_FINISHED) {
                game_finished = true;
                continue;
            }
            if (uGameState == GAME_STATE_CHANGE_LOCATION) {  // смена локации
                pAudioPlayer->StopChannels(-1, -1);
                PrepareWorld(0);
                uGameState = GAME_STATE_PLAYING;
                continue;
            }
            // if ((signed int)uGameState <= GAME_STATE_5 || uGameState ==
            // GAME_STATE_GAME_QUITTING_TO_MAIN_MENU)//GAME_STATE_NEWGAME_OUT_GAMEMENU,
            // GAME_STATE_LOADING_GAME
            if (uGameState == GAME_STATE_LOADING_GAME ||
                uGameState == GAME_STATE_NEWGAME_OUT_GAMEMENU ||
                uGameState == GAME_STATE_5 ||
                uGameState == GAME_STATE_GAME_QUITTING_TO_MAIN_MENU) {
                game_finished = true;
                continue;
            }
            if (uGameState == GAME_STATE_FINAL_WINDOW) {
                render->BeginScene();
                GUI_UpdateWindows();
                render->EndScene();
                render->Present();
                continue;
            }
            if (uGameState != GAME_STATE_PARTY_DIED) {
                engine->Draw();
                continue;
            }
            if (uGameState == GAME_STATE_PARTY_DIED) {
                pAudioPlayer->StopChannels(-1, -1);
                memset(&pParty->pHirelings[0], 0, 0x4Cu);
                memset(&pParty->pHirelings[1], 0, 0x4Cu);
                for (int i = 0; i < (signed int)pNPCStats->uNumNewNPCs; ++i) {
                    if (pNPCStats->pNewNPCData[i].field_24)
                        pNPCStats->pNewNPCData[i].uFlags &= 0xFFFFFF7Fu;
                }
                pMediaPlayer->PlayFullscreenMovie("losegame");
                if (pMovie_Track) pMediaPlayer->Unload();
                SaveGame(0, 0);
                ++pParty->uNumDeaths;
                for (uint i = 0; i < 4; ++i)
                    pParty->pPlayers[i].SetVariable(VAR_Award, 85);
                pParty->days_played_without_rest = 0;
                pParty->GetPlayingTime() +=
                    GameTime::FromDays(7);  // += 2580480
                HEXRAYS_LOWORD(pParty->uFlags) &= ~0x204;
                pParty->SetGold(0);
                pOtherOverlayList->Reset();
                memset(pParty->pPartyBuffs.data(), 0, 0x140u);

                if (pParty->bTurnBasedModeOn) {
                    pTurnEngine->End(true);
                    pParty->bTurnBasedModeOn = false;
                }
                for (int i = 1; i < 5; ++i) {
                    pPlayers[i]->conditions_times.fill(GameTime(0));
                    pPlayers[i]->pPlayerBuffs.fill(
                        SpellBuff());  // ???
                                       // memset(pParty->pPlayers[i].conditions_times.data(),
                                       // 0, 0xA0u);//(pConditions, 0, 160)
                                       // memset(pParty->pPlayers[i].pPlayerBuffs.data(),
                                       // 0, 0x180u);//(pPlayerBuffs[0], 0, 384)
                    pPlayers[i]->sHealth = 1;
                    uActiveCharacter = 1;
                }
                if (_449B57_test_bit(pParty->_quest_bits,
                                     PARTY_QUEST_FINISHED_EMERALD_ISLE)) {
                    pParty->vPosition.x = -17331;  // respawn in harmondale
                    pParty->vPosition.y = 12547;
                    pParty->vPosition.z = 465;
                    pParty->sRotationY = 0;
                    pLocationName = "out02.odm";
                } else {
                    pParty->vPosition.x = 12552;  // respawn on emerald isle
                    pParty->vPosition.y = 1816;
                    pParty->vPosition.z = 0;
                    pParty->sRotationY = 512;
                    pLocationName = "out01.odm";
                }
                strcpy(Source, pLocationName);
                pParty->uFallStartY = pParty->vPosition.z;
                pParty->sRotationX = 0;
                pParty->uFallSpeed = 0;
                pParty->field_6E4 = 0;
                pParty->field_6E0 = 0;
                if (pCurrentMapName != Source) {
                    pCurrentMapName = Source;
                    _5B65A8_npcdata_uflags_or_other = pParty->vPosition.x;
                    _5B65AC_npcdata_fame_or_other = pParty->vPosition.y;
                    _5B65B0_npcdata_rep_or_other = pParty->vPosition.z;
                    _5B65B4_npcdata_loword_house_or_other = pParty->sRotationY;
                    _5B65B8_npcdata_hiword_house_or_other = pParty->sRotationX;
                    dword_5B65C0 = 1;
                    PrepareWorld(1);
                }
                Actor::InitializeActors();

                int num_conscious_players = 0;
                int conscious_players_ids[4] = {-1, -1, -1, -1};
                for (int i = 0; i < 4; ++i) {
                    if (pParty->pPlayers[i].CanAct())
                        conscious_players_ids[num_conscious_players++] = i;
                }
                if (num_conscious_players) {
                    int idx =
                        conscious_players_ids[rand() % num_conscious_players];
                    Assert(idx >= 0);
                    pParty->pPlayers[idx].PlaySound(SPEECH_99, 0);
                }

                GameUI_StatusBar_OnEvent(localization->GetString(
                    524));  // "Once again you've cheated death!.." "Вы снова
                            // обхитрили смерть! …"
                uGameState = GAME_STATE_PLAYING;

                // need to flush messages here??
            }
        } while (!game_finished);

        pEventTimer->Pause();
        engine->ResetCursor_Palettes_LODs_Level_Audio_SFT_Windows();
        if (uGameState == GAME_STATE_LOADING_GAME) {
            sub_491E3A();
            GameUI_LoadPlayerPortraintsAndVoices();
            uGameState = GAME_STATE_PLAYING;
            bLoading = true;
            continue;
        }
        break;
    }
    current_screen_type = SCREEN_VIDEO;
    sub_491E3A();
}
