#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Address.h"
#include "Date.h"


class Person {
	std::string first_name;
	std::string last_name;
	Address address;
	Date date_of_birth;
public:
	Person();
	~Person();
	Person(std::string first_name, std::string last_name, Address address, Date date_of_birth);
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
	std::string GetFirstName()const;
	std::string GetLastName()const;
	Address GetAddress() const;
	Date GetDate() const;
	void SetFirstName(std::string name);
	void SetLastName(std::string name);
	void SetAddress(Address address);
	void SetDate(Date date);
	void ToBinary(std::ofstream& of);
	void LoadBinary(std::ifstream& ifs);

};

#endif // !PERSON_H

