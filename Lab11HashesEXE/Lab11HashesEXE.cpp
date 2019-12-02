// Lab11HashesEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..///Lab11HashesDLL/Lab11HashesDLL.h"

int main()
{
	hashTable myTable(100);
	myTable.addItem(30, 1);
	int length = myTable.getLength();
	hashNode* myNode = myTable.getVal(30);
	myNode = myTable.getVal(30);
	cout << myNode->value;
	length = myTable.getLength();
	cout << "hi" << endl;
	
	int size = -1;
	while (size < 0)
	{
		cout << "Choose the size of the hash" << endl;
		cin >> size;
	}
	hashTable myHash(size);

	int action = 0;	
	int userVal;
	int userKey;
	while (action != 5)
	{
		switch (action)
		{
		case 0:
			cout << "Please select one of the following: " << endl;
			cout << "1: Add an item to hash" << endl;
			cout << "2: Remove an item from the hash" << endl;
			cout << "3: Search the list for an item in the hash" << endl;
			cout << "4: Get the length of the hash" << endl;
			cout << "5: Quit" << endl;
			cin >> action;
			break;
		case 1:
			cout << "Adding an item to the hash" << endl;
			cout << "Input the value of the hash: ";
			cin >> userVal;
			cout << "Input the key for the has: ";
			cin >> userKey;

			myHash.addItem(userKey, userKey);

			action = 0;
			break;
		case 2:
			cout << "Removing an item from the hash" << endl;
			cout << "Enter the key of the item to be removed: ";
			cin >> userKey;
			//cout << endl;
			
			myHash.removeItem(userKey);

			action = 0;
			break;
		case 3:
			cout << "Getting item in the hash" << endl;
			cout << "Enter the key: ";
			cin >> userKey;
			cout << endl;

			myNode = myHash.getVal(userKey);

			if (myNode != NULL)
			{
				cout << "Returning value at " << userKey << endl;
				cout << "Value is " << myNode->value << endl;
			}
			else
			{
				cout << "Nothing was returned at this value" << endl;
			}
			action = 0;
			break;
		case 4:
			cout << "Getting the lenght of the hash" << endl;
			userVal = myHash.getLength();
			cout << "The length is " << userVal << endl;

			action = 0;
			break;
		default:
			cout << "Invalid Action!" << endl << "Please try again" << endl << endl;
			action = 0;
			break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
