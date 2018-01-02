#pragma once
#include "BaseLibrary.h"
class BahasaLibrary :
	public BaseLibrary
{
public:
	BahasaLibrary() {
		this->_countryCode = "ID";

		_numberStringMap = {
			{ -1, "min" },{ 0, "nol" },{ 1, "satu" },{ 2, "dua" },{ 3, "tiga" },{ 4, "empat" },{ 5, "lima" },{ 6, "enam" },{ 7, "tujuh" },{ 8, "delapan" },{ 9, "sembilan" },
			{ 10, "sepuluh" },{ 11, "sebelas" },{ 12, "dua belas" },{ 13, "tiga belas" },{ 14, "empat belas" },{ 15, "lima belas" },{ 16, "enam belas" },{ 17, "tujuh belas" },{ 18, "delapan belas" },{ 19, "sembilan belas" },
			{ 20, "dua puluh" },{ 30, "tiga puluh" },{ 40, "empat puluh" },{ 50, "lima puluh" },{ 60, "enam puluh" },{ 70, "tujuh puluh" },{ 80, "delapan puluh" },{ 90, "sembilan puluh" }
		};

		_zeroStringMap = {
			{ -3, "," },{ -1, "" },{ 2, "ratus" },{ 3, "ribu" },{ 6, "juta" },{ 9, "miliar" }
		};
	}
};

