// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB11HASHESDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB11HASHESDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB11HASHESDLL_EXPORTS
#define LAB11HASHESDLL_API __declspec(dllexport)
#else
#define LAB11HASHESDLL_API __declspec(dllimport)
#endif
#include <string>
using namespace std;


class LAB11HASHESDLL_API hashNode {
public:
	int key;
	int value;
	hashNode(int Key, int Val);
	hashNode();
private:
};


class LAB11HASHESDLL_API hashTable {
public:
	hashTable(int sizeOfTable);
	~hashTable();
	int getLength();
	hashNode * getVal(int key);
	int removeItem(int key);
	void addItem(int key, int val);
	int tableSize = 100;
private:
	int hash(int key); //Returns a hash of the table
	hashNode **table;
};