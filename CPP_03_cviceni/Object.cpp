#include "Object.h"

Object::Object(int id)
{
	this->id = id;
}

double Object::GetX() const
{
	return this->x;
}

void Object::SetX(double x)
{
	this->x = x;
}

double Object::GetY() const
{
	return this->y;
}

void Object::SetY(double y)
{
	this->y = y;
}

int Object::GetId() const
{
	return this->id;
}
