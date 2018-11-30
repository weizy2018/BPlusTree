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
void findTest();
void remove(BPlusTree<string, unsigned long int> * tree);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	testInit();
//	testCreate();
	findTest();
	return 0;
}
void menu() {

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
//	tree->printTree();

	delete tree;
}
void findTest() {
	BPlusTree<string, unsigned long int> * tree;
	tree = new BPlusTree<string, unsigned long int>("index.ind", 20, 8, false);
	printf("init success\n");
	string a("abc");
	while(a != "a") {
		cout << "input a key :";
		cin >> a;
		try {
			unsigned long int value = tree->get(a);
			cout << "value = " << value << endl;
		} catch (exception &e) {
			e.what();
		}
	}
	delete tree;
}
void testInit() {
	BPlusTree<string, unsigned long int> * tree;
	//const char * indexFileName, int keyLen, int valueLen, bool create)
	tree = new BPlusTree<string, unsigned long int>("index.ind", 20, 8, false);
	printf("init success\n");
//	remove(tree);
	cout << "remove OK" << endl;
	int a;
	cout << "input a:";
	cin >> a;
	if (a == 1) {
		tree->printTree();
	}
	//leafNode->self = 872 parent = 939
//	unsigned long int self = 1;
//	while (self != 0) {
//		cout << "input self : ";
//		cin >> self;
//		tree->test(self);
//	}

	delete tree;
}
void remove(BPlusTree<string, unsigned long int> * tree) {
	FILE * removeFile;
	char key[20];
	unsigned long int value;
	if ((removeFile = fopen("remove2.ts", "r")) == NULL) {
		printf("can't open the file: remove.ts");
		return;
	}
//	int i = 1;
	while (fscanf(removeFile, "%s%lu", key, &value) != EOF) {
//		cout << i << " : " << key << " " << value << endl;
		tree->remove(string(key), value);
//		i++;
	}

}


