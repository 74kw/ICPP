#pragma once
#ifndef TIME_H
#define TIME_H

#include "IComparable.h"
#include <string>

struct Time : IComparable{
private:
	int _hours;
	int _minutes;
	int _seconds;
public:
	Time();
	Time(int hours, int minutes, int seconds);
	~Time();
	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;


	virtual std::string ToString() const override;

	//virtual int compareTo(Time* obj) const;

	virtual int compareTo(IComparable* obj) const override;

};
#endif // !TIME_H