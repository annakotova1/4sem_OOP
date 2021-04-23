#include "dot.hpp"

void output_dot(dot_t d)
{
    printf("\t\t\t\tx = %lf", d.x);
    printf("\t\t\t\ty = %lf", d.y);
    printf("\t\t\t\tz = %lf\n", d.z);
}