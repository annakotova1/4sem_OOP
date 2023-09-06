#ifndef ABSTRACTSET_H
#define ABSTRACTSET_H

#include <cstddef>

template <typename Type>
class AbstractSet
{
public:
	explicit base_container();
    virtual ~AbstractSet() = 0;
    
    virtual size_t size() const noexcept {return _size;}
    virtual operator bool() const noexcept {return bool(size);}
    virtual bool isEmpty() const noexcept {return !bool(size);}

private:
    Type *array = nullptr;
    size_t size = 0;
    virtual void sort() = 0;
};

#endif