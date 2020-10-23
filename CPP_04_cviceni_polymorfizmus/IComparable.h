#pragma once
#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H


#include "IObject.h"

class IComparable : IObject {
public:
	IComparable();
	virtual ~IComparable(); // kdyby nebyl virtual destructor neprojde destructor v potomcích !!
	virtual int compareTo(IComparable* obj) const = 0;
	static void SortArray(IComparable** array, int arraySize);
};
#endif // !ICOMPARABLE_H