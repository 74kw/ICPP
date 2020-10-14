#include "MoveableObject.h"

double MoveableObject::GetUhelNatoceni() const
{
	return this->uhelNatoceni;
}

void MoveableObject::SetUhelNatoceni(double uhel)
{
	this->uhelNatoceni = uhel;
}

MoveableObject::MoveableObject(int id, double uhel) : Object(id)
{
	this->uhelNatoceni = uhel;
}
