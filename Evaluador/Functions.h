#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <string.h>
#include "PrecedenceObj.h"

using namespace std;

class [[nodiscard]]Functions //---> VC 17
{
public:
	Functions() {}

	[[maybe_unused]]inline int operator^(const int& num)noexcept(false) //---> VC 17
	{
		Functions temp(*this);
		int res = 0;
		return res;
	}

	[[maybe_unused]]inline int power(int num1, int num2)noexcept(false) //---> VC 17
	{
		return pow(num1, num2);
	}

	void toPostfix(string);
	void postfixToResult(string);
};
#endif

