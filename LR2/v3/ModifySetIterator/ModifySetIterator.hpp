#ifndef MODIFY_ITERATOR_HPP
#define MODIFY_ITERATOR_HPP

#include "ModifySetIterator.h"
namespace mySet
{
    template <typename SetType>
    ModifySetIterator<SetType>::ModifySetIterator(SetType *ptr, int size) : ConstSetIterator<SetType>(ptr, size)
    {}

    template <typename SetType>
    ModifySetIterator<SetType>::ModifySetIterator(ModifySetIterator<SetType> &iterator) : ConstSetIterator<SetType>(iterator)
    {}
    template <typename SetType>
    ModifySetIterator<SetType>::ModifySetIterator(Set<SetType> &set, int new_index) : ConstSetIterator<SetType>(set, new_index)
    {}

    // Получение элемента
    template <typename SetType>
    SetType &ModifySetIterator<SetType>::operator*()
    {
        this->check(__LINE__, __FILE__);
        return *this->getCurrentElement();
    }
    template <typename SetType>
    SetType *ModifySetIterator<SetType>::operator->()
    {
        this->check(__LINE__, __FILE__);
        return this->getCurrentElement();
    }
}
#endif