#ifndef ABSTRACT_ITERATOR_H
#define ABSTRACT_ITERATOR_H

#include <memory>

namespace mySet
{
    class AbstractIterator
    {
    public:
        AbstractIterator();
        AbstractIterator(int n_index, int n_max_index);
        AbstractIterator(const AbstractIterator& it);
        ~AbstractIterator();
    protected:
        int index = 0;
        int max_index = 0;
    };
}

#include "AbstractIterator.hpp"

#endif