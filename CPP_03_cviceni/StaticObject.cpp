#include "StaticObject.h"


StaticObject::StaticObject(int id, TypPrekazky typPrekazky) : Object(id)
{
	this->typPrekazky = typPrekazky;
}

TypPrekazky StaticObject::GetTypPrekazky() const
{
	return typPrekazky;
}
