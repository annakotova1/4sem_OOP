#ifndef POINT_H
#define POINT_H

#include "../../../inc/dot.hpp"
#include "../../../inc/logs.hpp"
#include "../../../inc/errors.hpp"
#include "../../../matrix/transform_matrix.hpp"

#include <stdio.h>
#include <stdlib.h>

struct point_t
{
    dot_t dot;
    int id;
};

int compare_points_id(const point_t &p, const int &id);
int download_point(point_t &result, FILE *file);
int transform_point(point_t &result, const matrix_t &matrix);

void output_point(point_t p);
int get_id(const point_t &point);

#endif