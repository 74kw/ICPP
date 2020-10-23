#include "Date.h"

Date::Date()
{
}

Date::Date(int day, int month, int year): _day(day),_month(month),_year(year)
{

}

Date::~Date()
{
}

std::string Date::ToString() const
{
    std::string s = std::to_string(this->_year) + "-" + std::to_string(this->_month) + "-" + std::to_string(this->_day);
    return s;
}

int Date::compareTo(IComparable* _obj) const
{
	Date* obj = dynamic_cast<Date*>(_obj);

	if (this->_year > obj->_year)
	{
		return 1;
	}
	else if (this->_year < obj->_year)
	{
		return -1;
	}
	else if (this->_year == obj->_year)
	{
		if (this->_month > obj->_month)
		{
			return 1;
		}
		else if (this->_month < obj->_month)
		{
			return -1;
		}
		else if (this->_month == obj->_month)
		{
			if (this->_day > obj->_day)
			{
				return 1;
			}
			else if (this->_day < obj->_day)
			{
				return -1;
			}
			else if (this->_day == obj->_day)
			{
				return 0;
			}
		}
	}
}
