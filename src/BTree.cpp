//============================================================================
// Name        : BTree.cpp
// Author      : weizy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "BPlusTree.h"

using namespace std;

void testCreate();
void testInit();
void remove(BPlusTree<string, unsigned long int> * tree);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	testInit();
//	testCreate();
	return 0;
}
void testCreate() {
	BPlusTree<string, unsigned long int> * tree;
	//const char * indexFileName, int keyLen, int valueLen, bool create)
	tree = new BPlusTree<string, unsigned long int>("index.ind", 20, 8, true);
	FILE * testFile;
	if ((testFile = fopen("index4.ts", "r")) == NULL) {
		printf("can't open test file\n");
		exit(0);
	}
	char key[20];
	long int value;
	while (fscanf(testFile, "%s%lu", key, &value) != EOF) {
		string str(key);
		tree->put(str, value);
	}
	cout << "main put OK" << endl;
	fclose(testFile);
	tree->printTree();

	delete tree;
}
void testInit() {
	BPlusTree<string, unsigned long int> * tree;
	//const char * indexFileName, int keyLen, int valueLen, bool create)
	tree = new BPlusTree<string, unsigned long int>("index.ind", 20, 8, false);
	printf("init success\n");
	remove(tree);
	cout << "remove OK" << endl;

//	tree->printTree();

	delete tree;
}
void remove(BPlusTree<string, unsigned long int> * tree) {
	FILE * removeFile;
	char key[20];
	unsigned long int value;
	if ((removeFile = fopen("remove.ts", "r")) == NULL) {
		printf("can't open the file: remove.ts");
		return;
	}
	while (fscanf(removeFile, "%s%lu", key, &value) != EOF) {
		tree->remove(string(key), value);
	}

}


