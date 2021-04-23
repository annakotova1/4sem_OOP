#ifndef LIST_EDGE_H
#define LIST_EDGE_H

#include <stdio.h>
#include <stdlib.h>

#include "../../inc/errors.hpp"
#include "edge/edge.hpp"
#include "../list_point/list_point.hpp"
#include "../../settings/settings.hpp"

struct list_edge_node_t
{
    edge_t data;
    list_edge_node_t *next;
};

int create_edge_node(list_edge_node_t **new_node, const edge_t &data);
int delete_edge_node(list_edge_node_t **node, edge_t &p);
int add_edge_node(list_edge_node_t **head, list_edge_node_t *new_node);
int delete_list_edge(list_edge_node_t **head);
int apply_for_each_edge(list_edge_node_t **head, int (*func)(edge_t&));

int download_list_edge(list_edge_node_t **head, FILE *file);
int draw_list_edge(list_edge_node_t *head, list_point_node_t *points, const command_settings_t &settings);

void output_list_edge(list_edge_node_t *head);

#endif