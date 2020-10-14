#pragma once
#ifndef MOVEABLE_OBJECT_H
#define MOVEABLE_OBJECT_H
#include "Object.h"


class MoveableObject : public Object{
private:
	double uhelNatoceni;

public:
	double GetUhelNatoceni() const;
	void SetUhelNatoceni(double uhel);
	//oproti zad�n� p�id�n constructor
	MoveableObject(int id, double uhel);

};

#endif // !MOVEABLE_OBJECT_H

