/*
 * DynArray.h
 *
 *  Created on: Jun 30, 2018
 *      Author: nachiketpatil
 */

#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include "BaseArray.h"

template <class T>
class DynArray: protected BaseArray {
public:

	DynArray() : BaseArray(sizeof(T)) {

	}
	virtual ~DynArray() {

	}

	unsigned int size() {
		return BaseArray::size();
	}

	void append(T item) {
		BaseArray::append((char*)(&item));
	}

	T& operator[] (unsigned int i) {
		return *((T*)get(i));
		//     * <derefrance> ((T* <informing that its pointer to T>)
		// int* ptr
	}

	void remove(unsigned int i) {
		BaseArray::remove(i);
	}

};

#endif /* DYNARRAY_H_ */
