#ifndef LIST_H
#define LIST_H 

#include "Node.hpp"

template<typename Type>
class List
{
private:
    Node<Type> *head = nullptr;
    Node<Type> *newNode(Type data);
    void addNodeToList(Node* new_node)
public:
    explicit List();
    ~List();
    void clear();
    void addElem(Type data);
    void findElem(Type data);
    bool inList();
    bool isEmpty();
    void sort();
};

#endif