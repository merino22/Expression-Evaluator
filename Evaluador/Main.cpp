#include <iostream>
#include <string>
#include <string.h>
#include <iterator>
#include <list>
#include "Functions.h"

using namespace std;

int main() {
	//char expression[100] = {0};
	string expression = "";
	Functions funcs;

	while (expression != "quit")
	{
		
		cout << "[Exp]>: ";
		//cin.getline(expression, sizeof(expression));
		getline(cin, expression);
		//string usable = " " + expression + " ";
		if (funcs.checkParenthesis(expression) == true && funcs.checkOperatorRules(expression) == true)
		{
			string refactoredExp = funcs.removeSpaces(expression);
			cout << "Refactored Expression: " << refactoredExp;
			funcs.toPostfix(expression);
		}
		else {
			cout << "ERROR: Syntax Error, missing parenthesis.";
		}
		

		
		/*for (int i = 0; i < expression.length(); i++) {
			int pos = expression.at(i);
			string res = "";
			if (isdigit(expression.at(i))) {
				res += pos;
			}
			else{
				if (res != " ")
				{
					expPostFija.push_back(res);
					res = "";
				}
				else {
					cout << "ERROR: Syntax error";
				}
				
			}
		}*/

		/*for (int i = 0; i < expression.length(); i++)
		{
			if (expression.at(i) == '(') {
				leftPar++;
			}
			else if (expression.at(i) == ')') {
				rightPar++;
			}
		}

		if (leftPar != rightPar) {
			cout << "\nError: Syntax error, missing Parenthesis";
		}*/

		/*if (!std::isdigit(expression.at(expression.length()-1)))
		{
			cout << "\nERROR: Syntax error at end of line, invalid character or incomplete expression -> " << expression.at(expression.length()-1);
		}*/

		cout << "\n\n";
	}
	
}