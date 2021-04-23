#include "rotate_matrix.hpp"

int make_rotate_matrix_x(matrix_t &matrix, const double &x)
{
	double radian_x;
	grad_to_radian(radian_x, x);

	matrix.pointers[1][1] = cos(radian_x);
	matrix.pointers[1][2] = sin(radian_x);
	matrix.pointers[2][1] = -sin(radian_x);
	matrix.pointers[2][2] = cos(radian_x);
	return OK;
}
int make_rotate_matrix_y(matrix_t &matrix, const double &y)
{
	double radian_y;
	grad_to_radian(radian_y, y);

	matrix.pointers[0][0] = cos(radian_y);
	matrix.pointers[2][0] = sin(radian_y);
	matrix.pointers[0][2] = -sin(radian_y);
	matrix.pointers[2][2] = cos(radian_y);
	return OK;
}
int make_rotate_matrix_z(matrix_t &matrix, const double &z)
{
	double radian_z;
	grad_to_radian(radian_z, z);

	matrix.pointers[0][0] = cos(radian_z);
	matrix.pointers[0][1] = sin(radian_z);
	matrix.pointers[1][0] = -sin(radian_z);
	matrix.pointers[1][1] = cos(radian_z);
	return OK;
}

void delete_matrixes_array(matrix_t array[MATRIXES_COUNT], const int &size)
{
    for (int i = 0; i < size; i++)
        mem_delete_matrix(array[i]);
}
int create_matrixes_array(matrix_t array[MATRIXES_COUNT], const int &size, const int &rows, const int &columns)
{
    int rc = OK;
    for (int i = 0; i < size && rc == OK; i++)
    {
        rc = mem_make_single_matrix(array[i], rows, columns);
        if (rc != OK)
            delete_matrixes_array(array, i);
    }
    return rc;
}

int make_rotate_matrixes_xyz(matrix_t array[MATRIXES_COUNT], const transform_settings_t &settings)
{
    int rc = make_rotate_matrix_x(array[0], settings.x);
    if (rc == OK)
        rc = make_rotate_matrix_y(array[1], settings.y);
    if (rc == OK)
        rc = make_rotate_matrix_z(array[2], settings.z);
    return rc;
}

int multiplicate_rotate_matrixes(matrix_t array[MATRIXES_COUNT], int &arr_size)
{
    int rc = mem_multiplicate_matrix(array[3], array[0], array[1]);
    arr_size++;
    if (rc == OK)
    {
        rc = mem_multiplicate_matrix(array[4], array[3], array[2]);
        arr_size++;
    }
    return rc;
}

int fill_rotate(matrix_t &matrix, const transform_settings_t &settings)
{
    matrix_t array[MATRIXES_COUNT];
    int arr_size = 3;
    int rc = create_matrixes_array(array, arr_size, MATRIX_SIZE, MATRIX_SIZE);
    if(rc != OK)
        return rc;
    if (rc == OK)
        rc = make_rotate_matrixes_xyz(array, settings);
    if (rc == OK)
        rc = multiplicate_rotate_matrixes(array, arr_size);
    if (rc == OK)
        mem_copy_matrix(matrix, array[4]);
    
    delete_matrixes_array(array, arr_size);
    return OK;
}
