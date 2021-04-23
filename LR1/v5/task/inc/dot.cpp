#include "dot.hpp"

void output_dot(dot_t d)
{
    printf("\t\t\t\tx = %lf", d.coord[MY_X]);
    printf("\t\t\t\ty = %lf", d.coord[MY_Y]);
    printf("\t\t\t\tz = %lf\n", d.coord[MY_Z]);
}

int get_dot_coordinate(int &coordinate, const dot_t dot, const int &i)
{
    if (i < 0 || i > 2)
        return ERR_ARGS;
    coordinate = dot.coord[i];
    return OK;
}