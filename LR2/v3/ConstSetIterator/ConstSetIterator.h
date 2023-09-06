#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include "../AbstractIterator/AbstractIterator.h"
#include "../SetException/SetException.h"

namespace mySet
{
    template <typename Type>
    class Set;

    template <typename SetType>
    class ConstSetIterator : public AbstractIterator
    {
    public:
        //ConstSetIterator(){};
        ConstSetIterator(SetType *ptr, int size);
        ConstSetIterator(ConstSetIterator<SetType> &iterator);
        ConstSetIterator(Set<SetType> &set, int new_index = 0);
        ~ConstSetIterator();

        //void init(SetType *ptr, int size);

		//SetIterator<SetType> operator=(const SetIterator<SetType>&);

        operator bool() const;

        const SetType operator*() const;
        const SetType *operator->() const;

		ConstSetIterator<SetType> operator=(const ConstSetIterator<SetType>&);

        // Инкремент и декремент
		ConstSetIterator<SetType>& operator++();
		ConstSetIterator<SetType> operator++(int);
		ConstSetIterator<SetType>& operator--();
		ConstSetIterator<SetType> operator--(int);

        // Увеличение и уменьшение итератора
        ConstSetIterator<SetType>& operator-=(int n);
        ConstSetIterator<SetType> operator-(int n) const;
        ConstSetIterator<SetType>& operator+=(int n);
        ConstSetIterator<SetType> operator+(int n) const;

        // Сравнение
		bool operator==(const ConstSetIterator<SetType>&) const;
		bool operator!=(const ConstSetIterator<SetType>&) const;
        
		bool operator>=(const ConstSetIterator<SetType>&) const;
		bool operator>(const ConstSetIterator<SetType>&) const;
		bool operator<(const ConstSetIterator<SetType>&) const;
		bool operator<=(const ConstSetIterator<SetType>&) const;

        bool check(int line, const char *file) const;

    protected:
        std::weak_ptr<SetType> start;

        SetType *getCurrentElement() const;
    };
}

#include "ConstSetIterator.hpp"

#endif /* CONST_ITERATOR_H */