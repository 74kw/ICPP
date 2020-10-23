#include "Game.h"

Game::Game(int velikost)
{
	this->objects = new Object*[velikost];
	for (int i = 0; i < velikost; i++)
	{
		objects[i] = nullptr;
	}
	objectsCount = 0;
}

Game::~Game()
{
	delete[] objects;
}

void Game::insertObject(Object* o)
{
	objects[objectsCount] = o;
	objectsCount++;
}

// zad�n� ned�v� moc smysl, lep�� by bylo pou��t std::vector<int>, nev�me velikost dynamick�ho pole...
int* Game::findIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax)
{
	int* pole = new int[objectsCount];
	for (int i = 0; i < objectsCount; i++)
	{
		pole[i] = NULL; //nepou��vat ve zkou�ce
	}
	int citacPole = 0;
	for (int i = 0; i < objectsCount; i++)
	{
		//bezpe�n� p�etypov�n�, kter� n�m pom��e zjistit jestli se jedn� o potomka... supluje instanceof
		if (StaticObject* st = dynamic_cast<StaticObject*>(objects[i]))
		{
			if ((st->GetX() >= xmin && st->GetX()<= xmax) && (st->GetY() >= ymin && st->GetY() <= ymax))
			{
				pole[citacPole] = st->GetId();
				citacPole++;
			}
		}
	}
	return pole;
}

MoveableObject** Game::findMoveableObjectsInArea(double x, double y, double r)
{
	MoveableObject** pole = new MoveableObject*[objectsCount];
	for (int i = 0; i < objectsCount; i++)
	{
		pole[i] = nullptr;
	}
	int citacPole = 0;
	for (int i = 0; i < objectsCount; i++)
	{
		//bezpe�n� p�etypov�n�, kter� n�m pom��e zjistit jestli se jedn� o potomka... supluje instanceof
		if (MoveableObject* st = dynamic_cast<MoveableObject*>(objects[i]))
		{
			if ( (pow((st->GetX() - x),2) + pow((st->GetY() - y),2)) < (pow(r,2)))
			{
				pole[citacPole] = st;
				citacPole++;
			}
			
		}
	}
	return pole;
}

MoveableObject** Game::findMoveableObjectsInArea(double x, double y, double r, double umin, double umax)
{
	MoveableObject** pole = new MoveableObject * [objectsCount];
	for (int i = 0; i < objectsCount; i++)
	{
		pole[i] = nullptr;
	}
	int citacPole = 0;
	for (int i = 0; i < objectsCount; i++)
	{
		//bezpe�n� p�etypov�n�, kter� n�m pom��e zjistit jestli se jedn� o potomka... supluje instanceof
		if (MoveableObject* st = dynamic_cast<MoveableObject*>(objects[i]))
		{
			if ((pow((st->GetX() - x), 2) + pow((st->GetY() - y), 2)) < (pow(r, 2)))
			{
				if (st->GetUhelNatoceni() > umin && st->GetUhelNatoceni() < umax)
				{
					pole[citacPole] = st;
					citacPole++;
				}
				
			}

		}
	}
	return pole;
}
