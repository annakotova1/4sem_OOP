#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include "ConstSetIterator.h"
namespace mySet
{
/*
template <typename Type>
ConstSetIterator<Type>::ConstSetIterator() : AbstractIterator()
{}*/

    template <typename Type>
    ConstSetIterator<Type>::ConstSetIterator(Type *ptr, int size) : AbstractIterator(0, size)
    {
        start = ptr;
    }

    template <typename Type>
    ConstSetIterator<Type>::ConstSetIterator(ConstSetIterator<Type> &iterator) : AbstractIterator(iterator)
    {
        start = iterator.start;
    }
    template <typename Type>
    ConstSetIterator<Type>::ConstSetIterator(Set<Type> &set, int new_index) : AbstractIterator(new_index, set.getSize())
    {
        start = set.elements;
    }

    // Деструктор
    template <typename Type>
    ConstSetIterator<Type>::~ConstSetIterator()
    {
        start.reset();
    }

    // Получение элемента
    template <typename Type>
    const Type ConstSetIterator<Type>::operator*() const
    {
        check(__LINE__, __FILE__);
        return *getCurrentElement();
    }
    template <typename Type>
    const Type *ConstSetIterator<Type>::operator->() const
    {
        check(__LINE__, __FILE__);
        return getCurrentElement();
    }

    // Копирование
    template <typename Type>
    ConstSetIterator<Type> ConstSetIterator<Type>::operator=(const ConstSetIterator<Type> &iterator)
    {
        check(__LINE__, __FILE__);
        index = iterator.index;
        max_index = iterator.max_index;
        start = iterator.start;
    }
    // Префиксный инкремент ++
    template <typename Type>
    ConstSetIterator<Type> &ConstSetIterator<Type>::operator++()
    {
        check(__LINE__, __FILE__);
        index++;
        return *this;
    }
    // Постфиксный инкремент ++
    template <typename Type>
    ConstSetIterator<Type> ConstSetIterator<Type>::operator++(int)
    {
        check(__LINE__, __FILE__);
        ConstSetIterator<Type> result(*this);
        ++(*this);
        return result;
    }

    // Префиксный декремент --
    template <typename Type>
    ConstSetIterator<Type> &ConstSetIterator<Type>::operator--()
    {
        check(__LINE__, __FILE__);
        index--;
        return *this;
    }
    // Постфиксный декремент --
    template <typename Type>
    ConstSetIterator<Type> ConstSetIterator<Type>::operator--(int)
    {
        check(__LINE__, __FILE__);
        ConstSetIterator<Type> result(this);
        --(*this);
        return result;
    }

    // +=
    template <typename Type>
    ConstSetIterator<Type> &ConstSetIterator<Type>::operator+=(int n)
    {
        check(__LINE__, __FILE__);
        index += n;
        check(__LINE__, __FILE__);
        return *this;
    }
    // +
    template <typename Type>
    ConstSetIterator<Type> ConstSetIterator<Type>::operator+(int n) const
    {
        check(__LINE__, __FILE__);
        ConstSetIterator<Type> Iterator(*this);
        Iterator += n;
        return Iterator;
    }
    // -=
    template <typename Type>
    ConstSetIterator<Type> &ConstSetIterator<Type>::operator-=(int n)
    {
        check(__LINE__, __FILE__);
        index-=n;
        check(__LINE__, __FILE__);
        return *this;
    }

    // -
    template <typename Type>
    ConstSetIterator<Type> ConstSetIterator<Type>::operator-(int n) const
    {
        check(__LINE__, __FILE__);
        ConstSetIterator<Type> Iterator(*this);
        Iterator -= n;
        return Iterator;
    }



    // Сравнение ==
    template <typename Type>
    bool ConstSetIterator<Type>::operator==(const ConstSetIterator<Type>&iterator2) const
    {
        check(__LINE__, __FILE__);
        if (getCurrentElement() != iterator2.getCurrentElement())
            return false;
        return true;
    }

    // Сравнение !=
    template <typename Type>
    bool ConstSetIterator<Type>::operator!=(const ConstSetIterator<Type>&iterator2) const
    {
        check(__LINE__, __FILE__);
        return !(*this == iterator2);
    }

    // Сравнение <=
    template <typename Type>
    bool ConstSetIterator<Type>::operator<=(const ConstSetIterator<Type>&iterator2) const
    {
        check(__LINE__, __FILE__);
        if (getCurrentElement() <= iterator2.getCurrentElement())
            return true;
        return false;
    }
    // Сравнение >=
    template <typename Type>
    bool ConstSetIterator<Type>::operator>=(const ConstSetIterator<Type>&iterator2) const
    {
        check(__LINE__, __FILE__);
        if (getCurrentElement() >= iterator2.getCurrentElement())
            return true;
        return false;
    }
    // Сравнение <
    template <typename Type>
    bool ConstSetIterator<Type>::operator<(const ConstSetIterator<Type>&iterator2) const
    {
        check(__LINE__, __FILE__);
        if (getCurrentElement() < iterator2.getCurrentElement())
            return true;
        return false;
    }
    // Сравнение >
    template <typename Type>
    bool ConstSetIterator<Type>::operator>(const ConstSetIterator<Type>&iterator2) const
    {
        check(__LINE__, __FILE__);
        if (getCurrentElement() > iterator2.getCurrentElement())
            return true;
        return false;
    }

    template <typename Type>
    Type *ConstSetIterator<Type>::getCurrentElement() const
    {
        check(__LINE__, __FILE__);
        std::shared_ptr<Type> copy_ptr = start.lock();
        return copy_ptr.get() + index;
    }


    template <typename Type>
    bool ConstSetIterator<Type>::check(int line, const char *file) const
    {
        //check(__LINE__, __FILE__);
        //printf("index = %d, max_index = %d\n", index, max_index);
        if (!start.expired() && !(index >= max_index))
            return true;
        //time_t currentTime = time();
        SetIncorrectIteratorException(__LINE__, __FILE__, typeid(*this).name());
        //printf("good check iter\n");
        return false;
    }
}
#endif