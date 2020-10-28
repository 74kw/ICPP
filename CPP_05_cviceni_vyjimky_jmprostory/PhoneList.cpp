#include "PhoneList.h"

Model::PhoneList::PhoneList()
{
	head = nullptr;
}

Model::PhoneList::~PhoneList()
{
	Node* node = head;
	while (node != nullptr) {
		Node* tmp = node->next;
		delete node;
		node = tmp;
	}
}
void Model::PhoneList::InsertToBegin(Entity::Person person)
{
	Node* node = new Node(person);
	if (head == nullptr)
	{
		this->head = node;
	}
	else
	{
		node->next = this->head;
		this->head = node;
	}
}

std::string Model::PhoneList::FindPhone(int id) const
{
	if (id < 0)
	{
		throw std::invalid_argument("ID must be positive value");
	}
	Node* node = head;
	while (node != nullptr) {
		if (node->data.CompareTo(id) == 0)
		{
			return node->data.GetPhone();
		}
		node = node->next;
	}
	throw MyException();
}

std::string Model::PhoneList::FindPhone(std::string jmeno) const
{
	if (jmeno == "")
	{
		throw std::invalid_argument("Name cannot be empty");
	}
	Node* node = head;
	while (node != nullptr) {
		if (node->data.CompareTo(jmeno) == 0)
		{
			return node->data.GetPhone();
		}
		node = node->next;
	}
	throw MyException();
}
