#include "../inc/my_vector.hpp"

int get_vector_lenght(double &lenght, const my_vector_coordinates &vec)
{
	lenght = sqrt((vec.x*vec.x) + (vec.y*vec.y) + (vec.z*vec.z));
	return OK;
}

int get_vector_coordinates(my_vector_coordinates &vec_coordinates, const my_vector &vec)
{
	vec_coordinates.x = (vec.start.x - vec.end.x);
	vec_coordinates.y = (vec.start.y - vec.end.y);
	vec_coordinates.z = (vec.start.z - vec.end.z);
	return OK;
}

int get_end_point(my_point &end, const my_point &start, 
	const my_vector_coordinates &vec_coordinates)
{	
	end.x = start.x + vec_coordinates.x;
	end.y = start.y + vec_coordinates.y;
	end.z = start.z + vec_coordinates.z;
	return OK;
}

int get_vector_single_vector(my_vector &single_vec, const my_vector &vec)
{
	my_vector_coordinates vec_coordinates;
	int rc = get_vector_coordinates(vec_coordinates, vec);
	double lenght;
	get_vector_lenght(lenght, vec_coordinates);
	my_vector_coordinates single_vec_coordinates;

	single_vec_coordinates.x = vec_coordinates.x/lenght;
	single_vec_coordinates.y = vec_coordinates.y/lenght;
	single_vec_coordinates.z = vec_coordinates.z/lenght;

	single_vec.start = vec.start;

	get_end_point(single_vec.end, single_vec.start, single_vec_coordinates);

	return rc;
}
