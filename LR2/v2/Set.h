#ifndef SET_H
#define SET_H

#include"AbstractContainer.h"
#include"Iterator.h"

template<typename Type>
class Set : AbstractContainer<Type>
{
public:
    // дружба с итератором
    friend class SetIterator;
    // Задать разными способами
    Set();
    Set(unsigned int num, ...);
	Set(const size_t num, const Type *arr);
    ~Set();

    // Присваивание 
    // Копирование

    // Пустое не пустое
    // Принадлежность элемента
    // Добавить элемент
    // Удалить элемент

    // Объединение                  ИЛИ
    // Пересечение                  И
    // Разность                     \
    // Симметрическая Разность      /\

    // Сравнение множеств
    
    // Вывод
private:
    // Сортировка
    void sort();

    // Элементы
    std::shared_ptr elements = nullptr; 
    // Размер выделенной памяти
    size_t memory_size = 0;
    // Кол-во добавленных элементов
    size_t elements_size = 0;
};

#endif