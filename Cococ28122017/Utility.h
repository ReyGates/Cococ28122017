#pragma once
class Utility
{
public:
	//static void AddMenu(MenuStruct menu);
	static void ClearScreen();
	static void PauseScreen();

	static std::vector<MenuStruct> MenuList;

	static std::string Input();

	static bool CheckDigit(std::string input);
};

