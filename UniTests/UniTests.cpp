#include "pch.h"
#include "CppUnitTest.h"
#include "functions.cpp";
#include "Validations.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UniTests
{
	TEST_CLASS(UniTests)
	{
	public:
		Validations obj;
		[[maybe_unused]]TEST_METHOD(TestMethod1) //---> VC 17
		{
			int number = 29;
			static_assert(1, "");
		}

		[[maybe_unused]]TEST_METHOD(CheckParenthesis)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkParenthesis(expression));
		}

		[[maybe_unused]]TEST_METHOD(CheckDecimals)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkDecimalPoints(expression));
		}

		[[maybe_unused]]TEST_METHOD(CheckOperatorRules)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkOperatorRules(expression));
		}

		[[maybe_unused]]TEST_METHOD(checkInvalidCharacters)
		{
			string expression = "2+(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkInvalidChars(expression));
		}

		[[maybe_unused]]TEST_METHOD(checkInvalidDenominator)
		{
			string expression = "2+(1+2)*2/(8-6)";
			Assert::IsTrue(obj.checkInvalidDenominator(expression));
		}

		[[maybe_unused]]TEST_METHOD(CheckParenthesisValidation)
		{
			string expression = "2+(1+2)*2+(8-6";
			Assert::IsTrue(obj.checkParenthesis(expression));
		}

		[[maybe_unused]]TEST_METHOD(CheckDecimalsValidation)
		{
			string expression = "2+4.-2 ";
			Assert::IsTrue(obj.checkDecimalPoints(expression));
		}

		[[maybe_unused]]TEST_METHOD(CheckOperatorRulesValidation)
		{
			string expression = "2++(1+2)*2+(8-6)";
			Assert::IsTrue(obj.checkOperatorRules(expression));
		}

		[[maybe_unused]]TEST_METHOD(checkInvalidCharactersValidation)
		{
			string expression = "2+(1+2)D*2+(8-6)";
			Assert::IsTrue(obj.checkInvalidChars(expression));
		}

		[[maybe_unused]]TEST_METHOD(checkInvalidDenominatorValidation)
		{
			string expression = "10+2(1*2)/0";
			Assert::IsTrue(obj.checkInvalidDenominator(expression));
		}
	};
}
