#ifndef SET_H
#define SET_H

#include "../AbstractContainer/AbstractContainer.h"
#include "../SetException/SetException.h"
#include "../ConstSetIterator/ConstSetIterator.h"

#include <stdarg.h>
#include <iostream>

namespace mySet
{
    template <typename SetType>
    class Set : public AbstractContainer
    {
    public:

        
        Set();
        Set(const int &num, ...);
        Set(const int &num, const SetType *arr);
        Set(const Set<SetType> &existSet);
        Set(Set<SetType> &&existSet);
        ~Set();/*{
            elements.reset();
        };*/
		Set<SetType>& operator=(const Set<SetType>& s);  // копирование
		Set<SetType>& operator=(Set<SetType>&& s); // присваивание 

        ConstSetIterator<SetType> cbegin() const;
        ConstSetIterator<SetType> cend() const;
        
        friend class ConstSetIterator<SetType>;
		// Вывод
        void output();
        

        bool inSet(const SetType &element);

        // Добавление элемента
        Set<SetType> operator+(const SetType &element) const;
        Set<SetType> &operator+=(const SetType &element);
        bool addElement(const SetType &element);

        // Удаление элемента
        Set<SetType> operator-(const SetType &element) const;
        Set<SetType> &operator-=(const SetType &element);
        bool removeElement(const SetType &element);

        // Вариации сравнения
        bool operator==(const Set<SetType>&set2) const;
        bool operator!=(const Set<SetType>&set2) const;

        bool operator<(const Set<SetType>&set2) const;
        bool isSub(const Set<SetType>&set2) const;
        bool operator>(const Set<SetType>&set2) const;
        bool isSupper(const Set<SetType>&set2) const;

        bool operator>=(const Set<SetType>&set2) const;
        bool operator<=(const Set<SetType>&set2) const;
        
        // Вариации объединения
        Set<SetType> operator+(const Set<SetType>set2) const;
        Set<SetType> &operator+=(const Set<SetType>set2);
        Set<SetType> operator|(const Set<SetType>set2) const;
        Set<SetType> &operator|=(const Set<SetType>set2);
        Set<SetType> unification(const Set<SetType>set2);

        // Вариации пересечения
        Set<SetType> operator*(const Set<SetType>set2) const;
        Set<SetType> &operator*=(const Set<SetType>set2);
        Set<SetType> operator&(const Set<SetType>set2) const;
        Set<SetType> &operator&=(const Set<SetType>set2);
        Set<SetType> intersection(const Set<SetType>set2);

        // Вариации разности
        Set<SetType> operator-(const Set<SetType>set2) const;
        Set<SetType> &operator-=(const Set<SetType>set2);
        Set<SetType> operator/(const Set<SetType>set2) const;
        Set<SetType> &operator/=(const Set<SetType>set2);
        Set<SetType> difference(const Set<SetType>set2);

        // Вариации симметричной разности
        Set<SetType> operator%(const Set<SetType>set2) const;
        Set<SetType> &operator%=(const Set<SetType>set2);
        Set<SetType> symmetric_difference(const Set<SetType>set2);

        int getSize() const;
        int getAllocSize() const;

        void clean();

    private:
        size_t allocated_size;
        const size_t alloc_step = 10;
        std::shared_ptr<SetType> elements;

        
        std::shared_ptr<SetType> allocMemory(const int &new_size);
    };
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Set<T>& s);
}

#include "Set.hpp"

#endif