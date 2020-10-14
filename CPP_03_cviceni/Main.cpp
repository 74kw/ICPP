#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define POCET_OBJEKTU 10
#include <iostream>
#include "Utils.h"
#include "Game.h"

int main() {
	Game* hra = new Game(POCET_OBJEKTU);
	//Object* test = new StaticObject(1, TypPrekazky::Skala);
	Object* testStatic1 = new StaticObject(11, TypPrekazky::Skala);
	testStatic1->SetX(0);
	testStatic1->SetY(0);
	Object* testStatic2 = new StaticObject(22, TypPrekazky::VelkaRostlina);
	testStatic2->SetX(8);
	testStatic2->SetY(8);

	hra->insertObject(testStatic1);
	hra->insertObject(testStatic2);

	int* pole = hra->findIdOfStaticObjects(-10, 10, -10, 10);
	for (int i = 0; i < 2; i++)
	{	
			std::cout << "Staticky object id je: " << pole[i] << std::endl;
		
	}
	Object* testMove1 = new MoveableObject(33, 90);
	testMove1->SetX(1);
	testMove1->SetY(1);
	Object* testMove2 = new MoveableObject(44, 180);
	testMove2->SetX(2);
	testMove2->SetY(2);
	Object* testMove3 = new MoveableObject(55, 240);
	testMove3->SetX(20);
	testMove3->SetY(20);
	hra->insertObject(testMove1);
	hra->insertObject(testMove2);
	hra->insertObject(testMove3);

	MoveableObject** pohybliveVKruhu = hra->findMoveableObjectsInArea(0, 0, 5);
	for (int i = 0; i < 2; i++)
	{	
		if (pohybliveVKruhu[i] != nullptr)
		{
			std::cout << "ID je v kruhu: "<<pohybliveVKruhu[i]->GetId() << std::endl;
		}
		
	}

	MoveableObject** pohybliveVKruhuUhel = hra->findMoveableObjectsInArea(0, 0, 5,150,200);
	for (int i = 0; i < 1; i++)
	{
		if (pohybliveVKruhuUhel[i] != NULL)
		{
			std::cout << "ID je v kruhu a splòuje uhel: " << pohybliveVKruhuUhel[i]->GetId() << std::endl;
		}

	}


	delete testStatic1;
	delete testStatic2;
	delete hra;
	delete pole;
	delete testMove1;
	delete testMove2;
	delete testMove3;
	delete pohybliveVKruhu;
	delete pohybliveVKruhuUhel;
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