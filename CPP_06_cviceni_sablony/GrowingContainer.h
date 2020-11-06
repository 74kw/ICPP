#pragma once
#ifndef GROWING_CONTAINER_H
#define GROWING_CONTAINER_H
#define INIT_SIZE 5
#include <iostream>


template <typename Type, int InitSize>
class GrowingContainer{
public:
	GrowingContainer();
	~GrowingContainer();
	void add(const Type& o);
	Type& operator [](int index);
	Type operator [](int index)const;
	unsigned int count() const;
	void addTo(int index, const Type& o);
	void remove(int index);

private:
	Type* array;
	unsigned arraySize;
	unsigned validNodesCount;
	unsigned growingCoefficient = 2;
	bool isFreeSpaceInArray() const;
	void expandArray();


};
template <typename Type, int InitSize>
GrowingContainer<Type,InitSize>::GrowingContainer()
{
	array = new Type[InitSize];
	arraySize = InitSize;
	validNodesCount = 0;
}
template <typename Type, int InitSize>
GrowingContainer<Type, InitSize>::~GrowingContainer()
{
	delete[] array;
}

template<typename Type, int InitSize>
void GrowingContainer<Type, InitSize>::add(const Type& o)
{
	if (isFreeSpaceInArray())
	{
		array[validNodesCount] = o;
		validNodesCount++;
	}
	else
	{
		expandArray();
		array[validNodesCount] = o;
		validNodesCount++;
	}
}

template<typename Type, int InitSize>
inline Type& GrowingContainer<Type, InitSize>::operator [](int index)
{
	if (index >= validNodesCount)
		throw std::out_of_range("Index is out of range");
	return array[index];
}

template<typename Type, int InitSize>
inline Type GrowingContainer<Type, InitSize>::operator [](int index) const
{
	if (index >= validNodesCount)
		throw std::out_of_range("Index is out of range");
	return array[index];
}

template<typename Type, int InitSize>
unsigned int GrowingContainer<Type, InitSize>::count() const
{
	return  validNodesCount;
}

template<typename Type, int InitSize>
void GrowingContainer<Type, InitSize>::addTo(int index, const Type& o)
{
	if (index > validNodesCount)
		throw std::out_of_range("Neplatný index");
	for (int i = validNodesCount; i > index; i--)
	{
		array[i] = array[i - 1];
	}
	array[index] = o;
	validNodesCount++;
}

template<typename Type, int InitSize>
void GrowingContainer<Type, InitSize>::remove(int index)
{
	if (index >= validNodesCount)
		throw std::out_of_range("Neplatný index");
	if (validNodesCount-1 == index)
		validNodesCount--;
	else
	{
		for (int i = index; i < validNodesCount - 1; i++)
		{
			array[i] = array[i + 1];
		}
		validNodesCount--;
	}

}

template<typename Type, int InitSize>
bool GrowingContainer<Type, InitSize>::isFreeSpaceInArray() const
{
	if (validNodesCount < arraySize)
		return true;
	return false;
}

template<typename Type, int InitSize>
void GrowingContainer<Type, InitSize>::expandArray()
{
	arraySize = arraySize * growingCoefficient;
	Type* newArray = new Type[arraySize];
	for (int i = 0; i < (arraySize/growingCoefficient); i++)
	{
		newArray[i] = array[i];
	}
	growingCoefficient++;
	delete[] array;
	array = newArray;
}

#endif // !GROWING_CONTAINER_H
