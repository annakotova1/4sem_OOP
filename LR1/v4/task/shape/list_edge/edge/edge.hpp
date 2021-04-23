#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>
#include <stdlib.h>
#include "../../../inc/dot.hpp" 
#include "../../../inc/logs.hpp" 
#include "../../../inc/errors.hpp" 
#include "../../../settings/settings.hpp"

struct edge_t
{
    int id1;
    int id2;
};

int download_edge(edge_t &result, FILE *file);
int draw_edge(const dot_t &draw_point1, const dot_t &draw_point2, command_settings_t settings);

void output_edge(edge_t &result);

#endif 