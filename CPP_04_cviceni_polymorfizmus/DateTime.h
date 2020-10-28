#pragma once
#ifndef DATETIME_H
#define DATETIME_H

#include "Date.h"

class DateTime : public IComparable{
private:
	//Date* _date;
	//Time* _time;
	Date _date;
	Time _time;
public:
	DateTime();
	DateTime(int year, int month, int day, int hour, int minute, int second);
	~DateTime();
	// Inherited via IComparable
	virtual std::string ToString() const override;
	virtual int compareTo(IComparable* obj) const override;
};

#endif // !DATETIME_H

