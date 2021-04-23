#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "errors.hpp"

// MATRIXES
struct my_matrix
{
	double **data;
	int rows;
	int columns;
};

// Для работы со структурой

int create_matrix(my_matrix &m, const int &rows, const int &columns);
void delete_matrix(my_matrix &m);
void matrix_copy(my_matrix &m1, const my_matrix &m2);

// Вспомогательные функции
int make_single_matrix(my_matrix &m);
void grad_to_radian(double &radians, const double &degrees); // Не относится к матрицам, может уехать в другой блок

int make_rotate_matrix_x(my_matrix &m, const double &x);
int make_rotate_matrix_y(my_matrix &m, const double &y);
int make_rotate_matrix_z(my_matrix &m, const double &z);
int make_rotate_matrix(const command_parametres &settings, my_matrix &m);


// В модуле будут:
// функция умножения матриц
int multiplicate_matrixes(my_matrix &res, const my_matrix &m1, const my_matrix &m2);
// функция формирования матрицы по параметрам
int make_transform_matrixes(my_matrix &m, const command_parametres &settings);
// функция формирования матрицы по координатам
int make_coordinates_matrixes(my_matrix &m, const my_point &coordinates);
int make_coordinates_from_matrixes(my_point &coordinates, const my_matrix &m);

#endif