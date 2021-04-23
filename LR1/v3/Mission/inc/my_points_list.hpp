#ifndef MYPOINTSLIST_H
#define MYPOINTSLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "errors.hpp"
#include "my_shape_point.hpp"

struct list_points_node
{
	shape_point data;
	list_points_node *next;
};

struct all_points
{
	list_points_node *head;
};

all_points &init();

// Создать узел
int create_points_node(list_points_node **node, shape_point &data);
// Добавить узел
int add_points_node(list_points_node **head, list_points_node *node);
// Удалить узел
int delete_points_node(list_points_node **node);
// Удалить список
int delete_points_list(list_points_node **head);

#endif