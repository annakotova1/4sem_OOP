#ifndef SET_HPP
#define SET_HPP

#include "Set.h"

namespace mySet
{

    template<typename Type>
    Set<Type>::Set()
    {
        this->size = 0;
        allocated_size = 0;
    }

    template<typename Type>
    Set<Type>::Set(const int &num, ...)
    {
        va_list arg;
        va_start(arg, num);
        size = 0;
        allocated_size = num;
        elements = allocMemory(allocated_size);
        
        Type elem;
        for (int i = 0; i < num; i++)
        {
            elem = va_arg(arg, Type);
            addElement(elem);
        }
        va_end(arg);
    }

    template<typename Type>
    Set<Type>::Set(const int &num, const Type *arr)
    {
        size = 0;
        allocated_size = num;
        elements = allocMemory(allocated_size);
        for (Type *i = arr; i < arr+num;i++)
        {
            addElement(*i);
        }
    }

    template<typename Type>
    Set<Type>::Set(const Set<Type> &existSet)
    {
        size = 0;
        allocated_size = existSet.allocated_size;
        elements = allocMemory(allocated_size);
        for (Type *i = existSet.elements.get(); i < existSet.elements.get() + existSet.size; i++)
        {
            addElement(*i);
        }
    }
    template<typename Type>
    Set<Type>::Set(Set<Type> &&existSet)
    {
        size = 0;
        allocated_size = existSet.allocated_size;
        elements = allocMemory(allocated_size);
        for (Type *i = existSet.elements.get(); i < existSet.elements.get() + existSet.size; i++)
        {
            addElement(*i);
        }
    }

    template<typename Type>
    Set<Type>::~Set()
    {
        elements.reset();
    }

    template<typename Type>
    bool Set<Type>::addElement(const Type &element)
    {
        if (!inSet(element))
        {
            if (size < allocated_size)
            {
                elements.get()[size] = element;
                size++;
            }
            else
            {
                if (allocated_size == 0)
                    allocated_size = 1;
                else 
                    allocated_size += alloc_step;
                std::shared_ptr<Type> buf = allocMemory(allocated_size);
                for (int i = 0; i < (int)size; i++)
                {
                    (buf.get())[i] = elements.get()[i];
                }
                buf.get()[size] = element;
                size++;
                elements.reset();
                elements = buf;
            }
            return true;
        }
        return false;
    }

    template<typename Type>
    bool Set<Type>::removeElement(const Type &element)
    {
        if (inSet(element))
        {
            int index = 0;
            for (int i = 0; i < (int)size; i++)
            {
                if ((elements.get())[i] == element)
                    index = i;
            }
            elements.get()[index] = elements.get()[size - 1];
            size--;
            return true;
        }
        return false;
    }
    // Объединение
    template<typename Type>
    Set<Type> Set<Type>::unification(Set<Type>set2)
    {
        for (int i = 0; i < set2.size; i++)
        {
            addElement(set2.elements.get()[i]);
        }
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator+(const Set<Type>set2) const
    {
        Set<Type> s1 = *this;
        s1.unification(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator+=(const Set<Type>set2)
    {
        unification(set2);
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator|(const Set<Type>set2) const
    {
        Set<Type> s1 = *this;
        s1.unification(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator|=(const Set<Type>set2)
    {
        unification(set2);
        return *this;
    }
    // Разность
    template<typename Type>
    Set<Type> Set<Type>::difference(Set<Type>set2)
    {
        for (int i = 0; i < set2.size; i++)
        {
            removeElement(set2.elements.get()[i]);
        }
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator-(const Set<Type>set2) const
    {
        Set<Type> s1 = *this;
        s1.difference(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator-=(const Set<Type>set2)
    {
        difference(set2);
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator/(const Set<Type>set2) const
    {
        Set<Type> s1 = *this;
        s1.difference(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator/=(const Set<Type>set2)
    {
        difference(set2);
        return *this;
    }
    // Симметрическая Разность
    template<typename Type>
    Set<Type> Set<Type>::symmetric_difference(Set<Type>set2)
    {
        for (int i = 0; i < set2.size; i++)
        {
            if (inSet(set2.elements.get()[i]))
                removeElement(set2.elements.get()[i]);
            else
                addElement(set2.elements.get()[i]);
        }
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator%(const Set<Type>set2) const
    {
        Set<Type> s1 = *this;
        s1.symmetric_difference(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator%=(const Set<Type>set2)
    {
        symmetric_difference(set2);
        return *this;
    }
    // Пересечение
    template<typename Type>
    Set<Type> Set<Type>::intersection(Set<Type>set2)
    {
        Set<Type> new_set;
        for (int i = 0; i < set2.size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (inSet(set2.elements.get()[i]))
                {
                    new_set.addElement(set2.elements.get()[i]);
                }
            }
        }
        *this = new_set;
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator*(const Set<Type>set2)const
    {
        Set<Type> s1 = *this;
        s1.intersection(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator*=(const Set<Type>set2)
    {
        intersection(set2);
        return *this;
    }
    template<typename Type>
    Set<Type> Set<Type>::operator&(const Set<Type>set2)const
    {
        Set<Type> s1 = *this;
        s1.intersection(set2);
        return s1;
    }
    template<typename Type>
    Set<Type> &Set<Type>::operator&=(const Set<Type>set2)
    {
        intersection(set2);
        return *this;
    }
    template<typename Type>
    bool Set<Type>::inSet(const Type &element)
    {
        for (int i = 0; i < (int)size; i++)
        {
            if (elements.get()[i] == element)
            {
                return true;
            }
        }
        return false;
    }

    template<typename Type>
    std::shared_ptr<Type> Set<Type>::allocMemory(const int &new_size)
    {
        std::shared_ptr<Type> buf = nullptr;
        try
        {
            std::shared_ptr<Type> sp(new Type[allocated_size]);
            buf = sp;
        }
        catch (std::bad_alloc)
        {
            std::cout << "memoryError";
            buf = nullptr;
            //throw SetMemoryException();
        }
        return buf;
    }

    template<typename Type>
    int Set<Type>::getAllocSize() const
    {
        return allocated_size;
    }

    template<typename Type>
    int Set<Type>::getSize() const
    {
        return size;
    }

    template<typename Type>
    void Set<Type>::clean()
    {
        size = 0;
        allocated_size = 0;
        elements.reset();
    }

    template<typename Type>
    ConstSetIterator<Type> Set<Type>::cbegin() const
    {
        ConstSetIterator<Type> it(*this, 0);
        return it;
    }
    template<typename Type>
    ConstSetIterator<Type> Set<Type>::cend() const
    {
        ConstSetIterator<Type> it(*this, size);
        return it;
    }
    template<typename Type>
    void Set<Type>::output()
    {
        const Set<Type>s1(*this);
        std::cout << s1;
    }

    template<typename Type>
    bool Set<Type>::isSupper(const Set<Type>&set2) const
    {
        for (int i = 0; i < set2.size; i++)
        {
            if (!inSet(set2.elements.get()[i]))
                return false;
        }
        return true;
    }
    template<typename Type>
    bool Set<Type>::isSub(const Set<Type>&set2) const
    {
        return set2.isSupper(*this);
    }

    template<typename Type>
    bool Set<Type>::operator<(const Set<Type>&set2) const
    {
        return (isSub(set2) && !(set2.isSub(*this)));
    }
    template<typename Type>
    bool Set<Type>::operator>(const Set<Type>&set2) const
    {
        return (isSupper(set2) && !(set2.isSupper(*this)));
    }
    template<typename Type>
    bool Set<Type>::operator==(const Set<Type>&set2) const
    {
        if (isSupper(set2) && (set2.isSupper(*this)))
            return true;
        return false;
    }
    template<typename Type>
    Set<Type>& Set<Type>::operator=(const Set<Type>&set2) 
    {
        elements.reset();
        allocated_size = 0;
        size = 0;
        for (int i = 0; i < set2.size; i++)
        {
            addElement(set2.elements.get()[i]);
        }
        return *this;
    }


    template<typename Type>
    bool Set<Type>::operator!=(const Set<Type>&set2) const
    {
        return !(*this == set2);
    }
    template<typename Type>
    bool Set<Type>::operator<=(const Set<Type>&set2) const
    {
        return !(*this == set2 && *this < set2);
    }
    template<typename Type>
    bool Set<Type>::operator>=(const Set<Type>&set2) const
    {
        return !(*this == set2 && *this > set2);
    }
    template<typename Type>
    std::ostream& operator<<(std::ostream& os, const Set<Type>& s)
    {
        os << "size: " << s.getSize() << " ";
        os << "{";
        for (size_t i = 0; i < s.getSize(); i++)
            os << " " << s.elements.get()[i];
        os << " }" << std::endl;
        return os;
    }
}

#endif