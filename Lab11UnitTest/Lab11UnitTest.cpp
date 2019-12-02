#include "pch.h"
#include "CppUnitTest.h"
#include "..///Lab11HashesDLL/Lab11HashesDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab11UnitTest
{
	TEST_CLASS(Lab11UnitTest)
	{
	public:
		
		TEST_METHOD(getLength1)
		{
			hashTable myTable(100);
			myTable.addItem(50, 5);
			myTable.addItem(51, 5);
			int length = myTable.getLength();
			Assert::AreEqual(length, 2);

		}
		TEST_METHOD(getLength2)
		{
			hashTable myTable(100);
			myTable.addItem(50, 5);
			myTable.addItem(51, 5);
			myTable.removeItem(51);
			myTable.removeItem(50);
			int length = myTable.getLength();
			Assert::AreEqual(length, 0);
		}
		TEST_METHOD(getVal1)
		{
		}
		TEST_METHOD(getVal2)
		{
		}
		TEST_METHOD(removeItem1)
		{
		}
		TEST_METHOD(gremoveItem2)
		{
		}
		TEST_METHOD(addItem1)
		{
		}
		TEST_METHOD(addItem2)
		{
		}

	};
}
