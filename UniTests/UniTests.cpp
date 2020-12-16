#include "pch.h"
#include "CppUnitTest.h"
#include "functions.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UniTests
{
	TEST_CLASS(UniTests)
	{
	public:
		Functions obj;
		TEST_METHOD(TestMethod1)
		{
			int number = 29;
			static_assert(1, "");
		}

		TEST_METHOD(CheckParenthesis)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkParenthesis(expression));
		}

		TEST_METHOD(CheckDecimals)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkDecimalPoints(expression));
		}

		TEST_METHOD(CheckOperatorRules)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkOperatorRules(expression));
		}

		TEST_METHOD(checkInvalidCharacters)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkInvalidChars(expression));
		}

		TEST_METHOD(checkInvalidDenominator)
		{
			string expression = "2+(1+2)*2/(8-6)";
			Assert::IsTrue(obj.checkInvalidDenominator(expression));
		}

		TEST_METHOD(CheckParenthesisValidation)
		{
			string expression = "2+(1+2)*2+(8-6";
			Assert::IsTrue(obj.checkParenthesis(expression));
		}

		TEST_METHOD(CheckDecimalsValidation)
		{
			string expression = "2+4.-2 ";
			Assert::IsTrue(obj.checkDecimalPoints(expression));
		}

		TEST_METHOD(CheckOperatorRulesValidation)
		{
			string expression = "2++(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkOperatorRules(expression));
		}

		TEST_METHOD(checkInvalidCharactersValidation)
		{
			string expression = "2+(1+2)D*2+(8-6)";
			Assert::IsTrue(obj.checkInvalidChars(expression));
		}

		TEST_METHOD(checkInvalidDenominatorValidation)
		{
			string expression = "10+2(1*2)/0";
			Assert::IsTrue(obj.checkInvalidDenominator(expression));
		}
	};
}
