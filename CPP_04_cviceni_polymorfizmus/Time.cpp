#include "Time.h"


Time::Time()
{
}

Time::Time(int hours, int minutes, int seconds) : _hours(hours), _minutes(minutes), _seconds(seconds)
{
}

Time::~Time()
{
}

int Time::GetHours() const
{
	return this->_hours;
}

int Time::GetMinutes() const
{
	return _minutes;
}

int Time::GetSeconds() const
{
	return _seconds;
}

std::string Time::ToString() const
{
    std::string s = std::to_string(this->_hours) + ":" + std::to_string(this->_minutes) + ":" + std::to_string(this->_seconds);
    return s;
}
//
//int Time::compareTo(Time* obj) const
//{
//	if (this->_hours > obj->_hours)
//	{
//		return 1;
//	}
//	else if (this->_hours < obj->_hours)
//	{
//		return -1;
//	}
//	else if (this->_hours == obj->_hours)
//	{
//		if (this->_minutes > obj->_minutes)
//		{
//			return 1;
//		}
//		else if (this->_minutes < obj->_minutes)
//		{
//			return -1;
//		}
//		else if (this->_minutes == obj->_minutes)
//		{
//			if (this->_seconds > obj->_seconds)
//			{
//				return 1;
//			}
//			else if (this->_seconds < obj->_seconds)
//			{
//				return -1;
//			}
//			else if (this->_seconds == obj->_seconds)
//			{
//				return 0;
//			}
//		}
//	}
//	
//}

int Time::compareTo(IComparable* _obj) const
{
	Time* obj = dynamic_cast<Time*>(_obj);

	if (this->_hours > obj->_hours)
	{
		return 1;
	}
	else if (this->_hours < obj->_hours)
	{
		return -1;
	}
	else if (this->_hours == obj->_hours)
	{
		if (this->_minutes > obj->_minutes)
		{
			return 1;
		}
		else if (this->_minutes < obj->_minutes)
		{
			return -1;
		}
		else if (this->_minutes == obj->_minutes)
		{
			if (this->_seconds > obj->_seconds)
			{
				return 1;
			}
			else if (this->_seconds < obj->_seconds)
			{
				return -1;
			}
			else if (this->_seconds == obj->_seconds)
			{
				return 0;
			}
		}
	}
	
}
