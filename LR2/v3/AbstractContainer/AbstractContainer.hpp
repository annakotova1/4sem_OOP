#ifndef ABSTRACT_CONTAINER_HPP
#define ABSTRACT_CONTAINER_HPP

#include "AbstractContainer.h"

namespace mySet
{
    bool AbstractContainer::isEmpty() const
    {
        if (size == 0)
            return true;
        return false;
    }

    size_t AbstractContainer::getSize() const
    {
        return size;
    }
}

#endif