#include "Time.h"
#include <cstdlib>
#include <ctime>
#include "Date.h"
#include "DateTime.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main() {
	srand((unsigned)time(0));


	int size = 10;
	IComparable** array = new IComparable * [size];
	for (int i = 0; i < size; i++)
	{
		int h = (rand() % 24);
		int m = (rand() % 60);
		int s = (rand() % 60);
		array[i] = new Time(h,m,s);
		if (Time* st = dynamic_cast<Time*>(array[i]))
		{
			std::cout << st->ToString() << std::endl;
		}
		
	}
	//SORT array
	std::cout << "_______________________________________" << std::endl;
	std::cout << "SERAZENE:"<< std::endl;
	std::cout << "_______________________________________" << std::endl;
	IComparable::SortArray(array, size);
	for (int i = 0; i < size; i++)
	{
		if (Time* st = dynamic_cast<Time*>(array[i]))
		{
			std::cout << st->ToString() << std::endl;
		}
	}
	//TEST DATE
	std::cout << "_______________________________________" << std::endl;
	IComparable** array2 = new IComparable * [size];
	for (int i = 0; i < size; i++)
	{
		int y = (rand() % 25 + 1997);
		int m = (rand() % 12 +1);
		int d = (rand() % 28 +1);
		array2[i] = new Date(d, m, y);
		if (Date* st = dynamic_cast<Date*>(array2[i]))
		{
			std::cout << st->ToString() << std::endl;
		}

	}
	//SORT date
	std::cout << "_______________________________________" << std::endl;
	std::cout << "SERAZENE:" << std::endl;
	std::cout << "_______________________________________" << std::endl;
	IComparable::SortArray(array2, size);
	for (int i = 0; i < size; i++)
	{
		if (Date* st = dynamic_cast<Date*>(array2[i]))
		{
			std::cout << st->ToString() << std::endl;
		}
	}
	/*TEST datetime*/
	std::cout << "_______________________________________" << std::endl;
	IComparable** array3 = new IComparable * [size];
	for (int i = 0; i < size; i++)
	{
		int y = (rand() % 25 + 1997);
		int m = (rand() % 12 + 1);
		int d = (rand() % 28 + 1);
		int h = (rand() % 24);
		int min = (rand() % 60);
		int s = (rand() % 60);
		array3[i] = new DateTime(y,m,d,h,min,s);
		if (DateTime* st = dynamic_cast<DateTime*>(array3[i]))
		{
			std::cout << st->ToString() << std::endl;
		}

	}
	//array3[2] = new DateTime(2010, 5, 5, 16, 01, 00);
	//array3[8] = new DateTime(2010, 5, 5, 16, 01, 00);
	//array3[5] = new DateTime(2010, 5, 5, 16, 00, 00);
	//array3[1] = new DateTime(2010, 5, 5, 16, 02, 00);

	//SORT datetime
	std::cout << "_______________________________________" << std::endl;
	std::cout << "SERAZENE:" << std::endl;
	std::cout << "_______________________________________" << std::endl;
	IComparable::SortArray(array3, size);
	for (int i = 0; i < size; i++)
	{
		if (DateTime* st = dynamic_cast<DateTime*>(array3[i]))
		{
			std::cout << st->ToString() << std::endl;
		}
	}
	//MEMORY CLEAR
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}
	delete[] array;
	for (int i = 0; i < size; i++)
	{
		delete array2[i];
	}
	delete[] array2;
	for (int i = 0; i < size; i++)
	{
		/*if (DateTime* st = dynamic_cast<DateTime*>(array3[i]))
		{*/
			delete array3[i];
		/*}*/
	}
	delete[] array3;

	//Memory LEAK Check start
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	//Memory Leak Check end
	return 0;
}
