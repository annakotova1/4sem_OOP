#ifndef SHAPE_H
#define SHAPE_H

#include "list_point/list_point.hpp"
#include "list_edge/list_edge.hpp"
#include "../settings/settings.hpp"
#include "../inc/logs.hpp"

struct shape_t
{
    list_point_node_t *point;
    list_edge_node_t *edge;
};

int download_shape(shape_t &new_shape, char *filename);
int transform_shape(shape_t &new_shape, const transform_settings_t &settings);
int draw_shape(shape_t &shape, const command_settings_t &settings);

shape_t &init_shape();
void delete_shape(shape_t &shape);

#endif