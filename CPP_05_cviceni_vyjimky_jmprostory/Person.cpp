#include "Person.h"

Entity::Person::Person(std::string name, std::string phone, int id) : name(name), phone(phone), id(id)
{
}

Entity::Person::~Person()
{
}

std::string Entity::Person::GetName() const
{
	return this->name;
}

std::string Entity::Person::GetPhone() const
{
	return this->phone;
}

int Entity::Person::GetId() const
{
	return this->id;
}

int Entity::Person::CompareTo(std::string jmeno) const
{
	if (this->name == jmeno)
	{
		return 0;
	}
	return -1;
}

int Entity::Person::CompareTo(int id) const
{
	if (this->id == id)
	{
		return 0;
	}
	return -1;
}
