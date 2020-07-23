//============================================================================
// Name        : DynamicArrayDemo.cpp
// Author      : Nikolay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DynArray.h"
#include <fstream>

using namespace std;

int main() {
	DynArray<int> test;
	for (int i=0; i < 10; i++) {
		test.append(i);
	}
	test[5] = -1;
	for (int i=0; i < test.size(); i++) {
		cout<< test[i] << " ";
	}
	cout << endl;

	test.remove(0);
	for (int i=0; i < test.size(); i++) {
		cout<< test[i] << " ";
	}
	cout << endl;

	test.remove(test.size()-1);
	for (int i=0; i < test.size(); i++) {
		cout<< test[i] << " ";
	}
	cout << endl;

	test.remove(3);
	for (int i=0; i < test.size(); i++) {
		cout<< test[i] << " ";
	}
	cout << endl;

	cout << endl;


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
