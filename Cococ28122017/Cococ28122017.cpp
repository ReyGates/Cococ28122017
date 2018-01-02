// Cococ28122017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BaseLibrary.h"
#include "EnglishLibrary.h"
#include "BahasaLibrary.h"
#include "Utility.h"

std::vector<BaseLibrary> Libraries;

MenuStruct *_currentMenu;
BaseLibrary *_currentLibrary;
StateEnum _currentState;

void InitializeMenu()
{
	MenuStruct *mainMenu = new MenuStruct;
	mainMenu->Title = "Main Menu";
	mainMenu->AddContent("1. Start Converter\n");
	mainMenu->AddContent("2. Select Library\n");
	mainMenu->AddContent("3. Exit\n");
	mainMenu->Parent = 0;
	mainMenu->State = StateEnum::Menu;

	MenuStruct *converterMenu = new MenuStruct;
	converterMenu->Title = "Converter Menu";
	converterMenu->AddContent("Input Number, ex: 99999\n");
	converterMenu->AddContent("Maximum Number, ex: 999999999\n");
	converterMenu->State = StateEnum::Converter;

	MenuStruct *libraryMenu = new MenuStruct;
	libraryMenu->Title = "Library Menu";
	libraryMenu->State = StateEnum::Library;
	
	for (int i = 0; i < Libraries.size(); i++)
	{
		libraryMenu->AddContent(std::to_string(i+1) + ". " + Libraries[i].GetCountryCode() + "\n");
	}

	mainMenu->AddSubMenu(converterMenu);
	mainMenu->AddSubMenu(libraryMenu);

	_currentMenu = mainMenu;
	_currentState = mainMenu->State;
}

void InitializeLibrary()
{
	EnglishLibrary *english = new EnglishLibrary();
	BahasaLibrary *bahasa = new BahasaLibrary();

	Libraries.push_back(*english);
	Libraries.push_back(*bahasa);

	_currentLibrary = english;
}

void Initialize()
{
	InitializeLibrary();
	InitializeMenu();
}

int main()
{
	Initialize(); 

	std::string input = "0";

	while (input.compare("exit") != 0)
	{
		Utility::ClearScreen(); 

		int i = 0;
		int menu = 0;

		if (Utility::CheckDigit(input))
		{
			i = std::stoi(input);
			menu = i - 1;

			if (_currentMenu->Content.size() > 0)
			{
				if (menu < _currentMenu->SubMenu.size() && menu >= 0)
				{
					_currentMenu = &_currentMenu->SubMenu[menu];
				}
			}
		}
		else
		{
			if (input.compare("back") == 0) 
			{
				if (_currentMenu->Parent != 0)
				{
					_currentMenu = _currentMenu->Parent;
				}
			}
		}

		//SET STATE
		_currentState = _currentMenu->State;

		//PRINT MENU
		_currentMenu->PrintHeader();
		_currentLibrary->PrintDescription();
		_currentMenu->PrintContent();

		//GET INPUT
		input = Utility::Input();

		if (Utility::CheckDigit(input))
		{
			int length = input[0] == '-' ? input.length() - 1 : input.length();

			if (length > 9)
			{
				input = "0";
			}
			else
			{
				int value = std::stoi(input);
				switch (_currentState)
				{
				case StateEnum::Menu:
					switch (value)
					{
					case 3:
						return 0;
						break;
					}

					break;

				case StateEnum::Converter:
					_currentLibrary->ProcessNumber(input);
					Utility::PauseScreen();
					break;

				case StateEnum::Library:
					int library = value - 1;

					if (library < Libraries.size())
					{
						_currentLibrary = &Libraries[library];
						input = "back";
					}
					break;
				}
			}
		}
	}

    return 0;
}

