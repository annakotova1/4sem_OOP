#ifndef ITERATOR_H
#define ITERATOR_H

#include "../AbstractIterator/AbstractIterator.h"

namespace mySet
{
    /*template <typename Type>
    class Set;*/

    template <typename SetType>
    class SetIterator : public AbstractIterator
    {
        SetIterator();
        SetIterator(SetType *ptr, int size);
        SetIterator(SetIterator<SetType> &iterator);
        ~SetIterator();

        void init(SetType *ptr, int size);

		SetIterator<SetType> operator=(const SetIterator<SetType>&);
		//SetIterator<SetType> operator=(const SetIterator<SetType>&);

        operator bool() const;

        const SetType operator*() const;
        const SetType operator->() const;

        // Инкремент и декремент
		SetIterator<SetType>& operator++();
		SetIterator<SetType> operator++(int);
		SetIterator<SetType>& operator--();
		SetIterator<SetType> operator--(int);

        // Увеличение и уменьшение итератора
        SetIterator<SetType>& operator-=(int n);
        SetIterator<SetType> operator-(int n) const;
        SetIterator<SetType>& operator+=(int n);
        SetIterator<SetType> operator+(int n) const;

        // Сравнение
		bool operator==(const SetIterator<SetType>&) const;
		bool operator!=(const SetIterator<SetType>&) const;
        
		bool operator>=(const SetIterator<SetType>&) const;
		bool operator>(const SetIterator<SetType>&) const;
		bool operator<(const SetIterator<SetType>&) const;
		bool operator<=(const SetIterator<SetType>&) const;

        bool check(int line) const;

    protected:
        std::weak_ptr<SetType> start = nullptr;

        SetType *getCurrentElement() const;
    };
}

#include "SetIterator.hpp"

#endif