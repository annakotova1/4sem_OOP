#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class SetException
{
public:
    SetException();
    ~SetException();
    virtual const char *what(){return errorText.c_str();};
    explicit SetException();
    explicit SetException(const char *message) :errorText(message){};
    explicit SetException(std::string &message) :errorText(message.c_str()){};
private:
    std::string errorText;
};

class SetMemoryException : public SetException
{
public:
    explicit SetMemoryException():SetException("Allocation memory error!\n"){}; 
};

#endif