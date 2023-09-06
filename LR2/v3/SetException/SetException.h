#ifndef SET_EXCEPTION_H
#define SET_EXCEPTION_H

#include <exception>
#include <string.h>
#include <string>

namespace mySet
{
    class SetException : std::exception
    {
    public:
        virtual const char *what()
        {
            return errorText.c_str();
        };
        explicit SetException():errorText("Unknow Exception\n"){};
        explicit SetException(const char *message) :errorText(message){errorText = errorText + "\n";};
        explicit SetException(int linenum, const char *filename, const char *funcname, const char *message)
        {
            std::string file(filename, strlen(filename));
            std::string line = std::to_string(linenum);
            std::string func(funcname, strlen(funcname));
            std::string nmessage(message, strlen(message));
            std::string t1("In file "), t2(" in line "), t3(" in "), t4("exception: ");
            std::string nl("\n");
            
            errorText = t1 + file + t2 + line  + t3+ func + t4 +nmessage + nl;
        };
        explicit SetException(std::string &message) :errorText(message.c_str()){errorText = errorText + "\n";};
        explicit SetException(int linenum, const char* filename, const char *funcname, std::string &message)
        {
            std::string file(filename, strlen(filename));
            std::string line = std::to_string(linenum);
            std::string func(funcname, strlen(funcname));
            std::string t1("In file "), t2(" in line "), t3(" in "), t4("exception: ");
            std::string nl("\n");

            errorText = t1 + file + t2 + line  + t3 + func + t4 + message + nl;
        };
        ~SetException(){};
    private:
        std::string errorText;
    };

    class SetMemoryException : public SetException
    {
    public:
        explicit SetMemoryException():SetException("Allocation memory error!"){}; 
        explicit SetMemoryException(int line, const char* filename, const char *funcname):
                        SetException(line, filename, funcname, "Allocation memory error!"){}; 
    };

    class SetIncorrectIteratorException : public SetException
    {
    public:
        explicit SetIncorrectIteratorException():SetException("Iterator is incorrect!"){}; 
        explicit SetIncorrectIteratorException(int line, const char* filename, const char *funcname):
                        SetException(line, filename, funcname, "Iterator is incorrect!"){}; 
    };
}

#endif