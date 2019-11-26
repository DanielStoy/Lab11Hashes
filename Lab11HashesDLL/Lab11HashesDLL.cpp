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

hashTable::hashTable(int sizeOfTable) {
	tableSize = sizeOfTable;
	table = new hashNode * [tableSize];
	for (int i = 0; i < tableSize; i++) {
		table[i] = NULL;
	}
}

hashTable::~hashTable() {

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
	return 0;
}

int hashTable::hash(int key) {
	return key % tableSize;
}