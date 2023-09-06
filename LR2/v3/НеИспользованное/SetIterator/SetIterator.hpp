#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "SetIterator.h"
using namespace mySet;

// Конструкторы 

template <typename Type>
SetIterator<Type>::SetIterator() : AbstractIterator()
{}

template <typename Type>
SetIterator<Type>::SetIterator(Type *ptr, int size) : AbstractIterator(0, size)
{
    start = ptr;
}

template <typename Type>
SetIterator<Type>::SetIterator(SetIterator<Type> &iterator) : AbstractIterator(iterator)
{
    start = iterator.start;
    /*index = iterator.index;
    end = iterator.end;*/
}

// Деструктор
template <typename Type>
SetIterator<Type>::~SetIterator()
{}

// Получение элемента
template <typename Type>
const Type SetIterator<Type>::operator*() const
{
    return start.get() + index;
}

// Копирование
template <typename Type>
SetIterator<Type> SetIterator<Type>::operator=(const SetIterator<Type> &iterator)
{
    index = iterator.index;
    max_index = iterator.max_index;
    start = iterator.start;
}
// Префиксный инкремент ++
template <typename Type>
SetIterator<Type> &SetIterator<Type>::operator++()
{
    index++;
    return *this;
}
// Постфиксный инкремент ++
template <typename Type>
SetIterator<Type> SetIterator<Type>::operator++(int)
{
    SetIterator<Type> result(this);
    ++(*this);
    return result;
}

// Префиксный декремент --
template <typename Type>
SetIterator<Type> &SetIterator<Type>::operator--()
{
    index--;
    return *this;
}
// Постфиксный декремент --
template <typename Type>
SetIterator<Type> SetIterator<Type>::operator--(int)
{
    SetIterator<Type> result(this);
    --(*this);
    return result;
}

// Сравнение ==
template <typename Type>
bool SetIterator<Type>::operator==(const SetIterator<Type>&iterator2) const
{
    if (index != iterator2.index)
        return false;
    if (start != iterator2.start)
        return false;
    return true;
}

// Сравнение !=
template <typename Type>
bool SetIterator<Type>::operator!=(const SetIterator<Type>&iterator2) const
{
    return !(*this == iterator2);
}

template <typename Type>
Type *SetIterator<Type>::getCurrentElement() const
{
    std::shared_ptr<Type> copy_ptr = start.lock();
    return copy_ptr.get() + index;
}


#endif