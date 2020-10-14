#pragma once
#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H
#include "Object.h"
#include "TypPrekazky.h"

class StaticObject : public Object {
private:
	TypPrekazky typPrekazky;
public:
	StaticObject(int id, TypPrekazky typPrekazky);
	TypPrekazky GetTypPrekazky() const;
};

#endif // !STATIC_OBJECT_H

