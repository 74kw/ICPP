#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	~Date();
	Date(int day, int month, int year);
	friend std::ostream& operator<<(std::ostream& os, const Date& obj);
	friend std::istream& operator>>(std::istream& is, Date& obj);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void ToBinary(std::ofstream& of);
	void LoadBinary(std::ifstream& ifs);

};

#endif // !DATE_H
