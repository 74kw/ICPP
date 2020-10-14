#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <iostream>

class Base {
	int id;

public:
	virtual void PrintMe() const 
	{
		std::cout << "Base" << std::endl; 
	}
};

class Advanced : public Base {
	int name;
};

class Advanced2 : public Base {
	int name;

public:
	virtual void PrintMe() const override
	{
		std::cout << "Advanced2" << std::endl;
	}
	~Advanced2() {}
};


#endif // !UTILS_H
