#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <memory>

template<typename Type>
class Node
{
public:
    Node(Type new_data):data(new_data), next(nullptr){};
    ~Node()
    {
        if (next)
            delete next;
    }
    void setNext(Node<Type> *new_next){next = new_next};
    Node<Type> *next(){return next};
    Type data(){return data;};
private:
    Type data = 0;
    std::shared_ptr<Node<Type>> ptr_next = nullptr;
};

#endif 