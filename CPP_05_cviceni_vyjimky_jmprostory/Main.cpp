#include "PhoneList.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


using namespace Entity;

int main() {
	Model::PhoneList* list = new Model::PhoneList();
	Person* osoba1 = new Person("Adam", "720 666 333", 1);
	Person* osoba2 = new Person("Karel", "724 200 100", 2);
	Person* osoba3 = new Person("Pepa", "728 111 222", 3);
	Person* osoba4 = new Person("David", "720 444 111", 4);
	Person* osoba5 = new Person("Martin", "720 200 300", 5);
	list->InsertToBegin(*osoba1);
	list->InsertToBegin(*osoba2);
	list->InsertToBegin(*osoba3);
	list->InsertToBegin(*osoba4);
	list->InsertToBegin(*osoba5);

	std::cout << "Telefonni cislo je: " << list->FindPhone(2) << std::endl;
	std::cout << "Telefonni cislo je: " << list->FindPhone("Pepa") << std::endl;
	try
	{
		std::cout << "Telefonni cislo je: " << list->FindPhone(-10) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << " error" << std::endl;
	}
	try
	{
		std::cout << "Telefonni cislo je: " << list->FindPhone(50) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << " error" << std::endl;
	}
	try
	{
		std::cout << "Telefonni cislo je: " << list->FindPhone("") << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << " error" << std::endl;
	}
	try
	{
		std::cout << "Telefonni cislo je: " << list->FindPhone("Lukas") << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << " error" << std::endl;
	}
	
	delete osoba1;
	delete osoba2;
	delete osoba3;
	delete osoba4;
	delete osoba5;
	delete list;
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