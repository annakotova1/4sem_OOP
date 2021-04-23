#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <cmath>
#include "../inc/logs.hpp"
#include "../inc/errors.hpp"
#include "../settings/settings.hpp"

struct matrix_t
{
    double **pointers;
    int rows;
    int columns;
};
#define MATRIX_SIZE 4
// Функции, работающие с памятью
int mem_create_matrix(matrix_t &new_matrix, const int &rows, const int &columns);
int mem_delete_matrix(matrix_t &matrix);
int mem_multiplicate_matrix(matrix_t &result, const matrix_t &matrix1, const matrix_t &matrix2);
int mem_make_single_matrix(matrix_t &matrix, const int &rows, const int &columns);
int mem_copy_matrix(matrix_t &matrix1, const matrix_t &matrix2);

// Функция вывода (для отладки)
void output_matrix(const matrix_t &matrix);

#endif