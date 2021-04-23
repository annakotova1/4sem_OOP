#ifndef MYSHAPEPOINT_H
#define MYSHAPEPOINT_H

#include <stdio.h>
#include <stdlib.h>
#include "errors.hpp"

typedef struct shape_point shape_point;

struct list_lines_node
{
	shape_point *adjacent_point;
	list_lines_node *next;
};

struct shape_point // Point with conections
{
	char name;
	my_point coordinates;
	list_lines_node *line_head;
};

// Функция создания узла списка связей
int create_lines_node(list_lines_node **node, shape_point *data);
// Функция добавления узла в список связей
int add_lines_node(list_lines_node **head, list_lines_node *node);
// Функция удаления узла списка связей
int delete_lines_node(list_lines_node **node);
// Функция удаления списка
int delete_lines_list(list_lines_node **head);

#endif