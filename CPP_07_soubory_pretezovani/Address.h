#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <fstream>


class Address {
	std::string street;
	std::string city;
	int zip_code;
public:
	Address();
	~Address();
	Address(std::string street, std::string city, int zip_code);
	friend std::ostream& operator<<(std::ostream& os, const Address& obj);
	friend std::istream& operator>>(std::istream& is, Address& obj);
	std::string GetStreet()const;
	std::string GetCity()const;
	int GetZipCode()const;
	void SetStreet(std::string street);
	void SetCity(std::string city);
	void SetZipCode(int zip);
	void ToBinary(std::ofstream& of);
	void LoadBinary(std::ifstream& ifs);

};

#endif // !ADDRESS_H
