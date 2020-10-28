#pragma once
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <exception>
#include <iostream>

class MyException : public std::exception
{
    //std::string what_message;
public:
    const char* what() const throw ()
    {
        return "User not found";
    }
};

#endif // !MY_EXCEPTION_H
