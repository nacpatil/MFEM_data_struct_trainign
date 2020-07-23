/*
 * BaseArray.h
 *
 *  Created on: Jun 30, 2018
 *      Author: nachiketpatil
 */

#ifndef BASEARRAY_H_
#define BASEARRAY_H_

class BaseArray {
private:
	char* data;
	unsigned int itemSize;
	unsigned int itemCount;
	unsigned int capacity;

	void resize(unsigned int new_capacity);

protected:
	char* get(unsigned int i);
	unsigned size();

	void remove(unsigned int i);
	void append(char* newdata);
	void set(unsigned int i, char* item);

public:
	BaseArray(unsigned int itemSize, unsigned int init_capacity=100);
	virtual ~BaseArray();
};

#endif /* BASEARRAY_H_ */
