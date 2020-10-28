#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H


#include <iostream>

class IObject {
public:
	virtual ~IObject() {};
	virtual std::string ToString() const = 0;
};
#endif // !IOBJECT_H