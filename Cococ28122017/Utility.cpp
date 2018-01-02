#include "stdafx.h"
#include "Utility.h"

void Utility::ClearScreen()
{
	for (int i = 0; i < 30; i++)
	{
		std::cout << "\n";
	}
}

void Utility::PauseScreen()
{
	std::cout << "Press Enter to Continue";
	_getch();
}

std::string Utility::Input()
{
	std::cout << "Your Input: ";

	std::string input = "";
	std::cin >> input;
	return input;
}

bool Utility::CheckDigit(std::string input)
{
	int start = 0;
	if (input[0] == '-')
	{
		start = 1;
	}

	for (int i = start; i < input.length(); i++)
	{
		if (isdigit(input[i]) == false)
		{
			return false;
		}
	}

	return true;
}
