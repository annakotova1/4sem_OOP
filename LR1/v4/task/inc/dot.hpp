#ifndef DOT_H
#define DOT_H

#include <stdio.h>

struct dot_t
{
    double x;
    double y;
    double z;
};

void output_dot(dot_t d);

#endif