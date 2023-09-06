#ifndef ABSTRACT_ITERATOR_HPP
#define ABSTRACT_ITERATOR_HPP

#include "AbstractIterator.h"
namespace mySet
{
    AbstractIterator::AbstractIterator()
    {}

    AbstractIterator::AbstractIterator(int n_index, int n_max_index)
    {
        index = n_index;
        max_index = n_max_index;
    }

    AbstractIterator::AbstractIterator(const AbstractIterator& it)
    {
        index = it.index;
        max_index = it.max_index;
    }

    AbstractIterator::~AbstractIterator()
    {}
}
#endif