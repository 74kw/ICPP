#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
#include <iostream>
#include "GrowingContainer.h"


int main() {
	GrowingContainer<std::string, 5> cont = GrowingContainer<std::string, 5>();
	for (int i = 0; i < 12; i++)
	{
		cont.add("String cislo: " + std::to_string(i));
		std::cout << cont[i] << std::endl;
	}
	std::cout << "Pocet prvku je: " << cont.count() << std::endl << std::endl;
	for (int i = 0; i < cont.count(); i++)
	{
		std::cout << cont[i] << std::endl;
	}
	std::cout << "Pocet prvku je: " << cont.count() << std::endl << std::endl;

	cont.remove(11);
	cont.addTo(11, std::to_string(20));
	//cont.addTo(3, std::to_string(4));
	for (int i = 0; i < cont.count(); i++)
	{
		std::cout << cont[i] << std::endl;
	}
	std::cout << "Pocet prvku je: " << cont.count() << std::endl << std::endl;
	

	//Memory LEAK Check start
	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	//_CrtDumpMemoryLeaks();
	//Memory Leak Check end
	return 0;
}
