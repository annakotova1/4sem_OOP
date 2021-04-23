#include "logs.hpp"

void print_line()
{
    for (int i = 0; i < 50; i++)
        printf("-");
    printf("\n");
}

void grad_to_radian(double &radians, const double &degrees)
{
	radians = degrees*M_PI/180;
}