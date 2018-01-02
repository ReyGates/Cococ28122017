// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <limits>

#include <stdio.h>
#include <tchar.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

enum StateEnum
{
	Menu,
	Converter,
	Library
};

//struct LibraryStruct
//{
//	std::string CountryCode;
//
//	void PrintDescription()
//	{
//		std::cout << "Current Library: " + CountryCode + "\n\n";
//	}
//};

struct MenuStruct {
	MenuStruct *Parent;

	StateEnum State;
	
	std::string Title = "";

	std::vector<std::string> Content;
	std::vector<MenuStruct> SubMenu;

	void AddSubMenu(MenuStruct *subMenu)
	{
		subMenu->Parent = this;
		SubMenu.push_back(*subMenu);
	}

	void AddContent(std::vector<std::string> content)
	{
		for (int i = 0; i < content.size(); i++)
		{
			Content.push_back(content[i]);
		}
	}

	void AddContent(std::string content)
	{
		Content.push_back(content);
	}

	void PrintHeader()
	{
		std::cout << Title + "\n";

		for (int i = 0; i < Title.length(); i++)
		{
			std::cout << "-";
		}

		std::cout << "\n";
	}

	void PrintContent()
	{
		for (int i = 0; i < Content.size(); i++)
		{
			std::cout << Content[i];
		}

		std::string description = "\nType ";
		if (SubMenu.size() > 0)
		{
			description += "[1 - " + std::to_string(Content.size()) + "] or ";
		}

		description += "'exit' to close program";

		if (Parent != NULL)
		{
			description += " or 'back' to back";
		}

		description += "\n";

		std::cout << description;
	}
};

// TODO: reference additional headers your program requires here
