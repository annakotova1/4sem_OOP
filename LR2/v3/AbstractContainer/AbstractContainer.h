#ifndef ABSTRACT_CONTAINER_H
#define ABSTRACT_CONTAINER_H
#include <cstddef>
#include <cstdio>
namespace mySet
{
    class AbstractContainer
    {
    public:
        bool isEmpty() const;
        size_t getSize() const;
        virtual void clean() = 0; 
        virtual ~AbstractContainer(){};
    protected:
        size_t size;
    };
}
#include "AbstractContainer.hpp"

#endif