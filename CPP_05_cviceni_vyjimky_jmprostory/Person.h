#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "MyException.h"

namespace Entity {

	class Person {
	private:
		std::string name;
		std::string phone;
		int id;
	public:
		Person(std::string name, std::string phone, int id);
		~Person();
		std::string GetName() const;
		std::string GetPhone() const;
		int GetId() const;
		int CompareTo(std::string jmeno) const;
		int CompareTo(int id) const;

	};
}
#endif // !PERSON_H
