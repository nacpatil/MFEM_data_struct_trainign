/*
 * BaseArray.cpp
 *
 *  Created on: Jun 30, 2018
 *      Author: nachiketpatil
 */
#include <memory>
#include <stdexcept>
#include "BaseArray.h"
#include <cstring>
#include <iostream>

using namespace std;

unsigned int min(unsigned int a, unsigned int b) {
	return a < b ? a : b;
}

void BaseArray::resize(unsigned int new_capacity) {
	char* new_data = new char[new_capacity * itemSize];
	memmove(new_data, data, min(new_capacity, itemCount) * itemSize); // (dest,src,
	delete[] data;
    data=new_data;
	capacity = new_capacity;
	itemCount = min(new_capacity, itemCount);
}

char* BaseArray::get(unsigned int i) {
	if (i >= itemCount) {
		throw invalid_argument("get");
	}
	return data + (i * itemSize);
}

unsigned BaseArray::size() {
	return itemCount;
}

void BaseArray::remove(unsigned int i) {
	// 0, 1, 2, 3, 4, 5. remove 3 -> 0, 1, 2, 4, 5
	if (i >= itemCount) {
		throw invalid_argument("remove");
	}
	if (i < (itemCount - 1)) {
		char *dest = data + (i * itemSize);
		memmove(dest, dest + itemSize, (itemCount - 1 - i) * itemSize);
	}
	itemCount--;
}

void BaseArray::append(char* src) {
	if (src == NULL) {
		throw invalid_argument("append");
	}
	if (itemCount == capacity) {
		resize(capacity + 1);
	}
	// 10 items itemCount = 10, valid indices are 0-9
	char *dest = data + ((itemCount++) * itemSize);
	std::cout<<*(int*)(src)<<std::endl;
	memmove(dest, src, itemSize);
}

void BaseArray::set(unsigned int i, char* src) {
	if (i >= itemCount || src == NULL) {
		throw invalid_argument("set");
	}
	char *dest = data + (i * itemSize);
	memmove(dest, src, itemSize);

}

BaseArray::BaseArray(unsigned int itemSize, unsigned int init_capacity) :
		data(NULL), itemSize(itemSize), itemCount(0), capacity(init_capacity)
{
     if (itemSize == 0 || capacity == 0) {
    	 throw invalid_argument("constructor");
     }
     data = new char[capacity * itemSize];
}

BaseArray::~BaseArray() {
	delete[] data;
}

