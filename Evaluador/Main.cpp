#include <iostream>
#include <string>
#include <string.h>
#include <iterator>
#include <list>
#include "Functions.h"
#include "Validations.h"
#include "Checkpoint.h"

using namespace std;

[[nodiscard]]int main() {
	auto expression = ""s;//---> VC 14
	Functions funcs;
	Validations validate;

	cout << "To quit application type 'quit'" << endl;
	while (expression != "quit")
	{
		int x = 0;
		cout << "[Exp]>: ";
		getline(cin, expression);
		Checkpoint check(expression);
		if (expression == "quit")
		{
			break;
		}
		check.passCheckpoint(check.errorCheck());
		cout << "\n\n";
	}

}