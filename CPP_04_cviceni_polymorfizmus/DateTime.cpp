#include "DateTime.h"

DateTime::DateTime()
{
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
{
    this->_date = new Date(day, month, year);
    this->_time = new Time(hour, minute, second);
}

DateTime::~DateTime()
{
    delete _time;
    delete _date;
}


std::string DateTime::ToString() const
{
    std::string s = this->_date->ToString() + " " + this->_time->ToString();
    return s;
}

int DateTime::compareTo(IComparable* obj) const
{
    DateTime* dt = dynamic_cast<DateTime*>(obj);
    if (this->_date->compareTo(dt->_date) == 1)
    {
        return 1;
    }
    else if (this->_date->compareTo(dt->_date) == -1)
    {
        return -1;
    }
    else if (this->_date->compareTo(dt->_date) == 0)
    {
        if (this->_time->compareTo(dt->_time) == 1)
        {
            return 1;
        }
        else if (this->_time->compareTo(dt->_time) == -1)
        {
            return -1;
        }
        else if (this->_time->compareTo(dt->_time) == 0)
        {
            return 0;
        }
    }
}
