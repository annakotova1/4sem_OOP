#ifndef SET_H
#define SET_H

#include"AbstractSet.h"

template<typename Type>
class Set
{
public:
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
    void sort();
};

#endif