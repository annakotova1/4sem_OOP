#ifndef ABSTRACT_SET_ITERATOR_H
#define ABSTRACT_SET_ITERATOR_H

#include "AbstractIterator.h"

namespace mySet
{
    template <typename Type>
    class Set;


    template <typename SetType>
    class AbstractSetIterator : public AbstractIterator<SetType>
    {
        AbstractSetIterator() : AbstractIterator(){};
        AbstractSetIterator(SetType *ptr, int size) : AbstractIterator(ptr, size){};
        AbstractSetIterator(Set<SetType> &set) : AbstractIterator(set.elements, set.size){};
        AbstractSetIterator(AbstractIterator<CotainerType> &iterator) : AbstractIterator(iterator){};
        virtual ~AbstractSetIterator() = 0;
    };
}

#include "AbstractSetIterator.hpp"

#endif