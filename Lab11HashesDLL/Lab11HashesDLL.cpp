#include "framework.h"
#include "Lab11HashesDLL.h"

hashNode::hashNode(int Key, int Val) {
	key = Key;
	value = Val;
}

hashNode::hashNode() {
	key = -1;
	value = 0;
}

//bool operator==(const hashNode lhs, const hashNode rhs)
//{
//	if (lhs.value == rhs.value)
//	{
//		return true;
//	}
//	return false;
//}

hashTable::hashTable(int sizeOfTable) {
	tableSize = sizeOfTable;
	table = new hashNode * [tableSize];
	for (int i = 0; i < tableSize; i++) {
		table[i] = NULL;
	}
}

//DO NOT MANUALLY INVOKE
hashTable::~hashTable() {
	for (int i = 0; i < tableSize; i++) {
		if (table[i] != NULL) {
			delete table[i];
			table[i] = NULL;
		}
	}
	delete[]table;
}

void hashTable::addItem(int key,int val) {
	int spot = hash(key);
	while (table[spot] != NULL && table[spot]->key != key)
		spot = hash(spot + 1);
	if (table[spot] != NULL) {
		delete table[spot];
	}
	table[spot] = new hashNode(key, val);
}

int hashTable::getLength() {
	int count = 0;
	for (int i = 0; i < tableSize; i++) {
		if (table[i] != NULL)
			count++;
	}
	return count;
}

hashNode * hashTable::getVal(int key) {
	int spot = hash(key);
	if (spot == -1)
	{
		return NULL;
	}
	while (table[spot] != NULL && table[spot]->key != key) {
		spot = hash(spot + 1);
	}
	if (table[spot] == NULL) {
		return NULL;
	}
	return table[spot];
}

int hashTable::removeItem(int key) {
	int spot = hash(key);
	if (spot == -1)
	{
		return -1;
	}
	int num = 0;
	while (table[spot] != NULL && table[spot]->key != key) {
		spot = hash(spot + 1);
	}
	if (table[spot] == NULL)
		return 0;
	num = table[spot]->value;
	delete table[spot];
	table[spot] = NULL;
	return num;
}

int hashTable::hash(int key) {
	if (key < 0 || key > tableSize)
	{
		return -1;
	}
	return key % tableSize;
}