#include "DateTime.h"

DateTime::DateTime()
{
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
{
    //this->_date = new Date(day, month, year);
    //this->_time = new Time(hour, minute, second);
    _date = Date(day, month, year);
    _time = Time(hour, minute, second);
}

DateTime::~DateTime()
{
   /* delete _time;
    delete _date;*/
}


std::string DateTime::ToString() const
{
    std::string s = _date.ToString() + " " + _time.ToString();
    return s;
}

int DateTime::compareTo(IComparable* obj) const
{
    DateTime* ds = dynamic_cast<DateTime*>(obj);
    DateTime dt = *ds;
    if (_date.compareTo(&dt._date) == 1)
    {
        return 1;
    }
    else if (_date.compareTo(&dt._date) == -1)
    {
        return -1;
    }
    else if (_date.compareTo(&dt._date) == 0)
    {
        if (_time.compareTo(&dt._time) == 1)
        {
            return 1;
        }
        else if (_time.compareTo(&dt._time) == -1)
        {
            return -1;
        }
        else if (_time.compareTo(&dt._time) == 0)
        {
            return 0;
        }
    }
}
