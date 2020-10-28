#pragma once
#ifndef PHONE_LIST_H
#define PHONE_LIST_H
#include "Person.h"

namespace Model {

	class PhoneList {
	private:
		class Node {
		private:
		public:
			Node* next;
			Entity::Person data;
			Node(Entity::Person data) : data(data), next(nullptr) {};
			~Node() {};
		};
		Node* head;
	public:
		PhoneList();
		~PhoneList();
		void InsertToBegin(Entity::Person person);
		std::string FindPhone(std::string jmeno)const;
		std::string FindPhone(int id)const;

	};
}
#endif // !PHONE_LIST_H


