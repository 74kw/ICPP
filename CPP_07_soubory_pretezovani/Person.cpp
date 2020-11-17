#include "Person.h"

Person::Person(std::string first_name, std::string last_name, Address address, Date date_of_birth)//:first_name(first_name),last_name(last_name),address(address),date_of_birth(date_of_birth)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->address = address;
    this->date_of_birth = date_of_birth;
}

Person::Person()
{
}
Person::~Person()
{
}

std::string Person::GetFirstName() const
{
    return first_name;
}

std::string Person::GetLastName() const
{
    return last_name;
}

Address Person::GetAddress() const
{
    return address;
}

Date Person::GetDate() const
{
    return date_of_birth;
}

void Person::SetFirstName(std::string name)
{
    first_name = name;
}

void Person::SetLastName(std::string name)
{
    last_name = name;
}

void Person::SetAddress(Address address)
{
    this->address = address;
}

void Person::SetDate(Date date)
{
    date_of_birth = date;
}

void Person::ToBinary(std::ofstream& of)
{
    //get string length
    int stringLength = this->first_name.length();
    //write string length
    of.write((const char*)&stringLength, sizeof(stringLength));
    //write string
    of.write(this->first_name.c_str(), stringLength);

    stringLength = this->last_name.length();

    of.write((const char*)&stringLength, sizeof(stringLength));
    of.write(this->last_name.c_str(), stringLength);

    date_of_birth.ToBinary(of);
    address.ToBinary(of);
}

void Person::LoadBinary(std::ifstream& ifs)
{
    int stringLength = 0;
    //read string length
    ifs.read((char*)&stringLength, sizeof(int));
    // create char with string length
    char* temp = new char[stringLength + 1];
    // dont forget ending character
    temp[stringLength] = '\0';
    // read string to temp char
    ifs.read(temp, stringLength);
    //save to string attribute
    first_name = temp;
    //delete helping pointer
    delete[] temp;
    
    stringLength = 0;
    ifs.read((char*)&stringLength, sizeof(int));
    char* temp2 = new char[stringLength + 1];
    temp2[stringLength] = '\0';
    ifs.read(temp2, stringLength);
    last_name = temp2;
    delete[] temp2;

    date_of_birth.LoadBinary(ifs);
    address.LoadBinary(ifs);
}



std::ostream& operator<<(std::ostream& os, const Person& obj)
{
    //os << obj.first_name << " " << obj.last_name << " " << obj.date_of_birth << obj.address << std::endl;
    os << obj.first_name << std::endl;
    os << obj.last_name << std::endl;
    os << obj.date_of_birth;
    os << obj.address << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Person& obj)
{
    std::string first_name, last_name;
    Address address;
    Date date;
    //std::cout << "Zadej Jmeno: " << std::endl;
    is >> first_name;
    obj.SetFirstName(first_name);
    //std::cout << "Zadej Prijmeni: " << std::endl;
    is >> last_name;
    obj.SetLastName(last_name);
    is >> date;
    obj.SetDate(date);
    is >> address;
    obj.SetAddress(address);
    
    return is;
}
