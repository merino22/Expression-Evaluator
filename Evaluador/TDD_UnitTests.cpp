#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TDDTEST)
{
public:
	TEST_METHOD(CHECKPARENTHESIS)
	{
		int number = 40;
		Assert::IsTrue(number > 30);
	}
};