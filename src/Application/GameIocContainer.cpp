#include "GameIocContainer.h"

#include "GameMenu.h"
#include "GameWindowHandler.h"

Menu* GameIocContainer::menu = nullptr;
GameWindowHandler* GameIocContainer::gameWindowHandler = nullptr;

Menu* GameIocContainer::ResolveGameMenu()
{
	if (!menu)
	{
		menu = new Menu();
	}
	return menu;
}

GameWindowHandler* GameIocContainer::ResolveGameWindowHandler()
{
	if (!gameWindowHandler)
	{
		gameWindowHandler = new GameWindowHandler();
	}
	return gameWindowHandler;
}
