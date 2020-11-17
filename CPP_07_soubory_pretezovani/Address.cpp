#include "Address.h"

Address::Address()
{
}

Address::~Address()
{
}

Address::Address(std::string street, std::string city, int zip_code):street(street),city(city),zip_code(zip_code)
{
}

std::string Address::GetStreet() const
{
    return street;
}

std::string Address::GetCity() const
{
    return city;
}

int Address::GetZipCode() const
{
    return zip_code;
}

void Address::SetStreet(std::string street)
{
    this->street = street;
}

void Address::SetCity(std::string city)
{
    this->city = city;
}

void Address::SetZipCode(int zip)
{
    this->zip_code = zip;
}

void Address::ToBinary(std::ofstream& of)
{
    int stringLength = street.length();

    of.write((const char*)&stringLength, sizeof(stringLength));
    of.write(street.c_str(), stringLength);

    stringLength = city.length();

    of.write((const char*)&stringLength, sizeof(stringLength));
    of.write(city.c_str(), stringLength);

    of.write((const char*)&zip_code, sizeof(zip_code));
}

void Address::LoadBinary(std::ifstream& ifs)
{
    int stringLength = 0;
    ifs.read((char*)&stringLength, sizeof(int));
    char* temp = new char[stringLength + 1];
    temp[stringLength] = '\0';
    ifs.read(temp, stringLength);
    street = temp;
    delete[] temp;

    stringLength = 0;
    ifs.read((char*)&stringLength, sizeof(int));
    char* temp2 = new char[stringLength + 1];
    temp2[stringLength] = '\0';
    ifs.read(temp2, stringLength);
    city = temp2;
    delete[] temp2;

    ifs.read((char*)&zip_code, sizeof(zip_code));
}


std::ostream& operator<<(std::ostream& os, const Address& obj)
{
    //os << " Adresa: " << obj.GetStreet() << ", " << obj.GetZipCode() << " " << obj.GetCity() << std::endl;
    os << obj.GetStreet() << std::endl;
    os << obj.GetZipCode() << std::endl;
    os << obj.GetCity() << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Address& obj)
{
    std::string street, city;
    int zip;

    //std::cout << "Zadej ulici: " << std::endl;
    is >> street;
    obj.SetStreet(street);
    //std::cout << "Zadej PSC: " << std::endl;
    is >> zip;
    obj.SetZipCode(zip);
    //std::cout << "Zadej mesto: " << std::endl;
    is >> city;
    obj.SetCity(city);


    return is;
}
