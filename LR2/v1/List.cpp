#ifndef LIST_HPP
#define LIST_HPP

#include "List.hpp"

template<typename Type>
List<Type>::~List()
{    
    clear();
}

template<typename Type>
Node<Type> *List<Type>::newNode(Type data)
{
    Node *new_node = new Node(data);
    return new_node;
};

template<typename Type>
void List<Type>::clear()
{
    /*Node<Type> *cur = head, *next = head->next();
    for (;next;cur = next, next = next->next())
    {
        delete cur;
    }
    delete cur;*/
    delete head;
}

template<typename Type>
void List<Type>::addElem(Type data)
{
    Node<Type> *new_node - newNode(data);
    addNodeToList(new_node);
};

template<typename Type>
void List<Type>::findElem(Type data)
{
    Node<Type> *new_node - newNode(data);
    addNodeToList(new_node);
};

template<typename Type>
List<Type>::List() : head(nullptr)
{}
template<typename Type>
void List<Type>::addNodeToList(Node<Type> new_node)
{
    Node<Type> *cur;
    for (cur = head; cur->next(); cur = cur.next());
    cur.setNext(new_node);
};

#endif