#include "IComparable.h"

IComparable::IComparable()
{
}

IComparable::~IComparable()
{
}

void IComparable::SortArray(IComparable** array, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j + 1]->compareTo(array[j]) == -1) {
                IComparable* tmp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}
