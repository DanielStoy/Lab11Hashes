// Lab11HashesEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <string>
#include <sstream>
#include "..///Lab11HashesDLL/Lab11HashesDLL.h"

typedef std::chrono::high_resolution_clock Clock;

int Task3();

int main()
{
	int size = 0;
	cout << "Run Time Tests? Press 1 to run" << endl;
	cin >> size;
	while(size == 1)
	{
		size = Task3();
		cout << "To run again press 1" << endl;
		cin >> size;
	}

	hashTable myTable(100);
	myTable.addItem(30, 1);
	int length = myTable.getLength();
	hashNode* myNode = myTable.getVal(30);
	myNode = myTable.getVal(30);
	cout << myNode->value;
	length = myTable.getLength();
	cout << "hi" << endl;
	
	size = -1;
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

int Task3()
{
	int amount;
	float sizeAdjuectment;
	std::string myString;
	cout << "Enter Amount" << endl;
	cin >> amount;
	cout << "Enter the adjustment value in digit form I.E. 150 -> 1.5" << endl;
	cin >> myString;
	stringstream(myString) >> sizeAdjuectment;
	float heapAmount = (float)amount * sizeAdjuectment;

	std::vector<int> num;
	for (int i = 0; i < amount; i++)
	{
		num.push_back(rand() % amount);
	}

	Clock::time_point in1;
	Clock::time_point in2;

	cout << "Insert items into said quque" << endl;
	in1 = Clock::now();
	hashTable testHash(int(heapAmount + 0.5));
	for (int i = 0; i < amount; i++)
	{
		testHash.addItem(i, num[i]);
	}
	in2 = Clock::now();
	cout << testHash.getLength() << " items were added to test hash" << endl;
	cout << "Hash insert took " << chrono::duration_cast<chrono::nanoseconds>(in2 - in1).count() << " nanoseconds" << endl;

	return testHash.getLength();
}