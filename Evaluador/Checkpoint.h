#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <iostream>
#include <string>
#include <string.h>
#include "Validations.h"
#include "Functions.h"

using namespace std;

class Checkpoint
{
public:
	Checkpoint(string _exp): str(_exp){}
	string str = "";
	string error = "";

	Functions func;
	Validations validate;

	string exp2 = validate.removeSpaces(str);

	// Go through all syntax error validations
	inline auto errorCheck() //---> VC 11, VC 17
	{
		if (!validate.checkDecimalPoints(exp2))
		{
			error = "SYNTAX ERROR: Invalid decimal value found";
			cout << error << endl;
		}
		if (!validate.checkInvalidChars(exp2))
		{
			error = "SYNTAX ERROR: Invalid character found";
			cout << error << endl;
		}
		if (!validate.checkInvalidDenominator(exp2))
		{
			error = "SYNTAX ERROR: Invalid denominator found";
			cout << error << endl;
		}
		if (!validate.checkOperatorRules(exp2))
		{
			error = "SYNTAX ERROR: Operator mismatch found";
			cout << error << endl;
		}
		if (!validate.checkParenthesis(exp2))
		{
			error = "SYNTAX ERROR: Parenthesis mismatch found";
			cout << error << endl;
		}
		 
		 return (error == "") ?  true : false;
	}
	// If no syntax errors were found run expression through postfix algorithm
	inline auto passCheckpoint(bool pass) //---> VC 17
	{
		if (pass)
		{
			func.toPostfix(exp2);
		}
	}
};
#endif // !CHECKPOINT_H
