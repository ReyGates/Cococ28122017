#include "stdafx.h"
#include "Utility.h"

#pragma once
class BaseLibrary
{
protected:
	std::string _countryCode;
	std::map<int, std::string> _numberStringMap;
	std::map<int, std::string> _zeroStringMap;

public:
	std::string Result = "";

	explicit BaseLibrary(){
	}

	BaseLibrary(std::string countryCode)
	{
		this->_countryCode = countryCode;
	}

	std::string GetCountryCode()
	{
		return _countryCode;
	}

	virtual void ProcessNumber(std::string number) {
		std::string minus = "";
		Result = "";

		if (number[0] == '-')
		{
			minus = number[0];
			number = number.substr(1);
			Result += _numberStringMap[-1] + " ";
		}

		long lNumber = std::stol(number);
		Utility::ClearScreen();
		std::cout << "Input\t: " + minus + std::to_string(lNumber) + "\n";

		std::string tNumberString = std::to_string(lNumber);

		if (lNumber > 0)
			Result += RecurNumber(tNumberString);
		else
			Result = _numberStringMap[0];

		std::cout << "Result\t: " + Result + "\n";
	}

	void PrintDescription()
	{
		std::cout << "Current Library: " + _countryCode + "\n\n";
	}

	std::string RecurNumber(std::string input)
	{
		std::string result = "";

		if (input.length() > 0)
		{
			int mod = input.length() % 3;
			int iSubstr = mod == 0 ? 1 : mod;

			std::string current = input.substr(0, iSubstr);
			std::string next = input.substr(iSubstr);

			if (std::stoi(current) != 0)
			{
				if (_numberStringMap[std::stoi(current)].compare("") == 0)
				{
					next = input.substr(iSubstr - 1);
					current = current.substr(0, 1) + "0";
				}

				result = _numberStringMap[std::stoi(current)] + " ";

				if (_zeroStringMap[next.length()].compare("") != 0 && std::stoi(input) > 9)
				{
					result += _zeroStringMap[next.length()];

					if (mod != 0 && std::stoi(next) != 0)
					{
						result += _zeroStringMap[-3];
					}

					result += " ";
				}
				else
				{
					if (mod == 0)
					{
						result += _zeroStringMap[2] + " ";
					}
					else if (mod == 2 && std::stoi(current) > 19 && next.length() > 0)
					{
						result[result.length() - 1] = _zeroStringMap[-1][0];
					}
				}

				if (mod == 0 && std::stoi(next) != 0 && _zeroStringMap[-2].compare("") != 0)
				{
					result += _zeroStringMap[-2] + " ";
				}
			}

			//This is how it works step by step
			//std::cout << current + "\t" + (mod == 0 ? (std::stoi(current) != 0 ? _zeroStringMap[2] : "") : (std::stoi(input) > 9 ? _zeroStringMap[next.length()] : "")) + "\n";
			
			if (std::stoi(input) == 0)
			{
				if (next.length() > 2)
				{
					result += _zeroStringMap[next.length()] + " ";
				}

				next = "";
			}

			result += RecurNumber(next);
		}

		return result;
	}
};