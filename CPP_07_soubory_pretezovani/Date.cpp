#include "Date.h"

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
    //os << " Narozen: "<< obj.year << "-" << obj.month << "-" << obj.day;
    os << obj.year << std::endl;
    os << obj.month << std::endl;
    os << obj.day << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Date& obj)
{
    int year, month, day;
    //std::cout << "Zadej rok: " << std::endl;
    is >> year;
    obj.SetYear(year);
    //std::cout << "Zadej mesic: " << std::endl;
    is >> month;
    obj.SetMonth(month);
    //std::cout << "Zadej den: " << std::endl;
    is >> day;
    obj.SetDay(day);

    return is;
}

int Date::GetDay() const
{
    return day;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetYear() const
{
    return year;
}

void Date::SetDay(int day)
{
    this->day = day;
}

void Date::SetMonth(int month)
{
    this->month = month;
}

void Date::SetYear(int year)
{
    this->year = year;
}
void Date::ToBinary(std::ofstream& of)
{
    of.write((const char*)&year, sizeof(year));
    of.write((const char*)&month, sizeof(month));
    of.write((const char*)&day, sizeof(day));
}

void Date::LoadBinary(std::ifstream& ifs)
{
    ifs.read((char*)&year, sizeof(year));
    ifs.read((char*)&month, sizeof(month));
    ifs.read((char*)&day, sizeof(day));
}

Date::Date()
{
}

Date::~Date()
{
}
Date::Date(int day, int month, int year): day(day),month(month),year(year)
{
}

