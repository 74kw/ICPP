#pragma once
#ifndef DATE_H
#define DATE_H

#include "Time.h"

class Date : public IComparable{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int day, int month, int year);
	~Date();
	// Inherited via IComparable
	virtual std::string ToString() const override;
	virtual int compareTo(IComparable* obj) const override;
};

#endif // !DATE_H
