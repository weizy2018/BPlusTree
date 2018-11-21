//============================================================================
// Name        : BTree.cpp
// Author      : weizy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BPlusTree.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	BPlusTree<int, int> * tree;
	//const char * indexFileName, int keyLen, int valueLen, bool create)
	tree = new BPlusTree<int, int>("index.ind", 20, 8, true);

	delete tree;
	return 0;
}
