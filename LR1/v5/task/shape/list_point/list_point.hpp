#ifndef LIST_POINT_H
#define LIST_POINT_H

#include <stdio.h>
#include <stdlib.h>
#include "point/point.hpp"
#include "../../inc/errors.hpp"
#include "../../matrix/transform_matrix.hpp"
#include "../../inc/logs.hpp"

struct list_point_node_t
{
    point_t data;
    list_point_node_t *next;
};

int create_point_node(list_point_node_t **new_node, const point_t &data);
int delete_point_node(list_point_node_t **node, point_t &p);
int add_point_node(list_point_node_t **head, list_point_node_t *new_node);
int delete_list_point(list_point_node_t **head);
int apply_for_each_point(list_point_node_t **head, int (*func)(point_t&));
int find_point_by_id(list_point_node_t *head, dot_t &result, const int &id);


int get_shape_center(dot_t &center, list_point_node_t *head);

int download_list_point(list_point_node_t **head, FILE *file);
int transform_list_point(list_point_node_t *head, const matrix_t &transform_matrix);

void output_list_point(list_point_node_t *head);

#endif