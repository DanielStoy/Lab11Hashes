#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab11HashesDLL\Lab11HashesDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab11UnitTest
{
	TEST_CLASS(Lab11UnitTest)
	{
	public:
		TEST_METHOD(GetLength_NormalTest)
		{
			hashTable myHash(10);
			myHash.addItem(0, 5);
			myHash.addItem(1, 5);
			myHash.addItem(2, 5);
			myHash.addItem(3, 5);
			myHash.addItem(4, 5);
			myHash.addItem(5, 5);

			int expLength = 6;
			int actualLength = myHash.getLength();

			Assert::AreEqual(expLength, actualLength);
		}

		TEST_METHOD(GetLength_EmptyTest)
		{
			hashTable myHash(10);

			int expLength = 0;
			int actualLength = myHash.getLength();

			Assert::AreEqual(expLength, actualLength);
		}

		TEST_METHOD(AddItem_Test)
		{
			hashTable myHash(10);
			myHash.addItem(0, 5);
			myHash.addItem(1, 5);
			myHash.addItem(2, 5);
			myHash.addItem(3, 5);
			myHash.addItem(4, 5);
			myHash.addItem(5, 10);

			int expLength = 6;
			int actualLength = myHash.getLength();

			hashNode* testNode = myHash.getVal(5);
			int actualVal = testNode->value;

			Assert::AreEqual(expLength, actualLength);
			Assert::AreEqual(10, actualVal);
		}

		TEST_METHOD(AddItem_KeyConflictTest)
		{
			hashTable myHash(10);
			myHash.addItem(0, 10);
			myHash.addItem(1, 20);
			myHash.addItem(1, 30);
			myHash.addItem(1, 40);
			myHash.addItem(1, 50);
			myHash.addItem(1, 60);

			int expLength = 2;
			int actualLength = myHash.getLength();

			hashNode* testNode = myHash.getVal(1);
			int actualVal = testNode->value;

			Assert::AreEqual(expLength, actualLength);
			Assert::AreEqual(60, actualVal);
		}

		TEST_METHOD(RemoveItem_Test)
		{
			hashTable myHash(10);
			myHash.addItem(0, 5);
			myHash.addItem(1, 5);
			myHash.addItem(2, 5);
			myHash.addItem(3, 5);
			myHash.addItem(4, 5);
			myHash.addItem(5, 10);

			myHash.removeItem(3);
			myHash.removeItem(4);

			int expLength = 4;
			int actualLength = myHash.getLength();
			bool deleteVal;
			if (myHash.getVal(4) == NULL)
			{
				deleteVal = true;
			}
			else
			{
				deleteVal = false;
			}

			Assert::AreEqual(expLength, actualLength);
			Assert::IsTrue(deleteVal);
		}

		TEST_METHOD(RemoveItem_InvalidKey)
		{
			hashTable myHash(10);
			myHash.addItem(0, 5);
			myHash.addItem(1, 5);
			myHash.addItem(2, 5);
			myHash.addItem(3, 5);
			myHash.addItem(4, 5);
			myHash.addItem(5, 10);

			Assert::AreEqual(0, myHash.removeItem(7));
			Assert::AreEqual(-1, myHash.removeItem(15));
			Assert::AreEqual(-1, myHash.removeItem(-4));			
		}

		TEST_METHOD(GetVal_Test)
		{
			hashTable myHash(10);
			myHash.addItem(0, 5);
			myHash.addItem(1, 53);
			myHash.addItem(2, 5);
			myHash.addItem(3, 5);
			myHash.addItem(4, 5);
			myHash.addItem(5, 10);

			hashNode* testNode = myHash.getVal(1);

			Assert::AreEqual(1, testNode->key);
			Assert::AreEqual(53, testNode->value);
		}

		TEST_METHOD(GetVal_InvalidKey)
		{
			hashTable myHash(10);
			myHash.addItem(0, 5);
			myHash.addItem(1, 5);
			myHash.addItem(2, 5);
			myHash.addItem(3, 5);
			myHash.addItem(4, 5);
			myHash.addItem(5, 10);

			hashNode* testNode1 = myHash.getVal(7);
			hashNode* testNode2 = myHash.getVal(-1);
			hashNode* testNode3 = myHash.getVal(20);

			bool nullReturned;
			if (testNode1 == NULL)
			{
				nullReturned = true;
			}
			else
			{
				nullReturned = false;
			}
			Assert::IsTrue(nullReturned);

			if (testNode2 == NULL)
			{
				nullReturned = true;
			}
			else
			{
				nullReturned = false;
			}
			Assert::IsTrue(nullReturned);

			if (testNode3 == NULL)
			{
				nullReturned = true;
			}
			else
			{
				nullReturned = false;
			}
			Assert::IsTrue(nullReturned);
		}
	};
}
