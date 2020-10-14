#pragma once
#ifndef GAME_H
#define GANE_H
#include "Object.h"
#include "MoveableObject.h"
#include <iostream>
#include "StaticObject.h"
#include <math.h>

class Game {
private:
	Object** objects;
	int objectsCount;
public:
	Game(int velikost);
	~Game();
	void insertObject(Object* o); //insert object to array
	int* findIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax); //return array of static object ids in area
	MoveableObject** findMoveableObjectsInArea(double x, double y, double r); // return array of pointers to MOs in circle area
	MoveableObject** findMoveableObjectsInArea(double x, double y, double r,double umin, double umax); //same as previous with Angle check

};

#endif // !GAME_H

