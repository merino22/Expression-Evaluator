#include <iostream>
#include <string>
#include <string.h>
#include <iterator>
#include <list>
#include "Functions.h"
#include "Validations.h"

using namespace std;

[[nodiscard]]int main() {
	auto expression = ""s;//---> VC 14
	Functions funcs;
	Validations validate;
	while (expression != "quit")
	{
		int x = 0;
		cout << "[Exp]>: ";
		getline(cin, expression);
		static_assert(true, "Wrong character");
		if (expression == "quit")
		{
			break;
		}
		if (validate.checkParenthesis(expression) == true)
		{
			if (validate.checkOperatorRules(expression) == true)
			{
				if (validate.checkDecimalPoints(expression) == true)
				{
					if (validate.checkInvalidChars(expression) == true)
					{
						string refactoredExp = validate.removeSpaces(expression);
						cout << "Refactored Expression: " << refactoredExp;
						string postfixExpression = funcs.toPostfix(refactoredExp);
						funcs.postfixToResult(postfixExpression);
					}
					else
					{
						cout << "ERROR: Syntax Error, alphanumeric characters encountered.";
					}
				}
				else
				{
					cout << "ERROR: Syntax Error,  float value mismatch";
				}
			}
			else
			{
				cout << "ERROR: Syntax Error, operator mismatch";
			}
		}
		else {
			cout << "ERROR: Syntax Error, missing parenthesis.";
		}

		cout << "\n\n";
	}

}