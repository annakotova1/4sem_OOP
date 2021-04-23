#ifndef MYCAMERA_H
#define MYCAMERA_H

#include "my_vector.hpp"
#include "my_matrix.hpp"

struct my_camera
{
	my_matrix transform_matrix;
	my_point center;
	int width;
	int height;
};

int init_camera

#endif