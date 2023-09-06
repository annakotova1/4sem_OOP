#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H

#include <iostream>

template<typename Type>
class AbstractIterator
{
public:
    AbstractIterator();
    AbstractIterator(const AbstractIterator& iter):
    {
        cur_ptr = iter.ptr;
    };
    AbstractIterator(Type *ptr):
    {
        cur_ptr = ptr;
    };


    AbstractIterator<Type> &operator = (const AbstractIterator<Type>&iter){
		if (this != &iter)
		{
			this->ptr = iter.ptr;
		}
		return *this;
	};
    AbstractIterator<Type> &operator ++ ()
    {
        ++cur_ptr;
        return *this;
    };
    AbstractIterator<Type> operator ++ (int)
    {
        AbstractIterator<Type> temp = (*this);
        ++(*this);
        return temp;
    };
    AbstractIterator<Type> &operator -- ()
    {
        --cur_ptr;
        return *this;
    };
    AbstractIterator<Type> operator -- (int)
    {
        AbstractIterator<Type> temp = (*this);
        -(*this);
        return temp;
    };

    bool operator == (const AbstractIterator<Type>&)
    {
		return this->ptr == iter.ptr;
    };
    bool operator != (const AbstractIterator<Type>&)
    {
		return this->ptr != iter.ptr;
    };

    virtual ~AbstractIterator() = 0;
    
private:
    std::shared_ptr<Type> cur_ptr;
};

template<typename Type>
class SetIterator : public AbstractIterator
{
	SetIterator(const SetIteratorConst<ValueType> &ptr):cur_ptr(ptr){};
	SetIterator(std::shared_ptr<ValueType> ptr):cur_ptr(ptr){};

    Type &operator *() const
    {
        return *cur_ptr;
    };
    Type &operator ->() const
    {
        return cur_ptr;
    };
};

template<typename Type>
class ConstSetIterator : public AbstractIterator
{
	ConstSetIterator(const SetIteratorConst<ValueType> &ptr):cur_ptr(ptr){};
	ConstSetIterator(std::shared_ptr<ValueType> ptr):cur_ptr(ptr){};

    const Type &operator *() const
    {
        return *cur_ptr;
    };
    const Type &operator ->() const
    {
        return cur_ptr;
    };
};

#endif