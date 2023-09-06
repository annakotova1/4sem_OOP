#ifndef MODIFY_ITERATOR_H
#define MODIFY_ITERATOR_H

#include "../ConstSetIterator/ConstSetIterator.h"
namespace mySet
{
    template <typename SetType>
    class ModifySetIterator : public ConstSetIterator<SetType>
    {
    public:
        ModifySetIterator(SetType *ptr, int size);
        ModifySetIterator(ModifySetIterator<SetType> &iterator);
        ModifySetIterator(Set<SetType> &set, int new_index = 0);

        SetType &operator*();
        SetType *operator->();
    };
}
#include "ModifySetIterator.hpp"

#endif