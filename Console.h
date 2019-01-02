#pragma once
#include <iostream>
class Console
{
public:
	Console();
	~Console();

	//Making the returned variables of these functions static prevents them from being changed accidentally
	static int GetN();
	static bool ShowCalculations();
	static bool ShowDetail();
};

