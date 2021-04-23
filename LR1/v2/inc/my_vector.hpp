#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "errors.hpp"
#include "my_point.hpp"
#include <cmath>

struct my_vector_coordinates
{
	double x;
	double y;
	double z;
};

struct my_vector
{
	my_point start;
	my_point end;
};

int get_vector_lenght(double &lenght, const my_vector_coordinates &vec);
int get_vector_coordinates(my_vector_coordinates &vec_coordinates, const my_vector &vec);
int get_end_point(my_point &end, const my_point &start, 
	const my_vector_coordinates &vec_coordinates);
int get_vector_single_vector(my_vector &single_vec, const my_vector &vec);

#endif