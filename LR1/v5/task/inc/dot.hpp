#ifndef DOT_H
#define DOT_H

#include <stdio.h>
#include "errors.hpp"

#define MY_X 0
#define MY_Y 1
#define MY_Z 2

struct dot_t
{
    double coord[3];
};

void output_dot(dot_t d);

int get_dot_coordinate(int &coordinate, const dot_t dot, const int &i);

#endif