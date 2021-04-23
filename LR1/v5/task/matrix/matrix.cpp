#include "matrix.hpp"

int mem_create_matrix(matrix_t &new_matrix, const int &rows, const int &columns)
{
    new_matrix.pointers = (double **)calloc(rows, sizeof(double *));
    if (!new_matrix.pointers)
        return ERR_MEMORY;

    new_matrix.rows = 0;
    new_matrix.columns = columns;

    for (new_matrix.rows = 0; new_matrix.rows < rows; new_matrix.rows++)
    { 
        new_matrix.pointers[new_matrix.rows] = (double *)calloc(columns ,sizeof(double));
        if (!new_matrix.pointers[new_matrix.rows])
        {
            mem_delete_matrix(new_matrix);
            return ERR_MEMORY;
        }
    }
    return OK;
}

int mem_copy_matrix(matrix_t &matrix1, const matrix_t &matrix2)
{
    int rc = mem_create_matrix(matrix1, matrix2.rows, matrix2.columns);
    if (rc != OK)
        return rc;

    for (int i = 0; i < matrix2.rows; i++)
    {
        for (int j = 0; j < matrix2.columns; j++)
            matrix1.pointers[i][j] = matrix2.pointers[i][j];
    }
    return OK;
}

int mem_delete_matrix(matrix_t &matrix)
{
    for (int i = 0; i < matrix.rows; i++)
        free(matrix.pointers[i]);
    free(matrix.pointers);
    return OK;
}

int mem_multiplicate_matrix(matrix_t &result, const matrix_t &matrix1, const matrix_t &matrix2)
{
    if (matrix1.columns != matrix2.rows)
        return ERR_ARGS;
    int rc = mem_create_matrix(result, matrix1.rows, matrix2.columns);
    if (rc != OK) 
        return rc;
        
    for (int i = 0; i < matrix1.rows; i++)
    {
        for (int j = 0; j < matrix2.columns; j++)
        {
            for (int k = 0; k < matrix2.rows; k++)
            {
                result.pointers[i][j] += matrix1.pointers[i][k] * matrix2.pointers[k][j];
            }
        }
    }
    return OK;
}

int mem_make_single_matrix(matrix_t &matrix, const int &rows, const int &columns)
{
    int rc = mem_create_matrix(matrix, rows, columns);
    if (rc != OK)
        return rc;

    for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.columns; j++)
		{
			if (i == j)
				matrix.pointers[i][j] = 1;
			else
				matrix.pointers[i][j] = 0;
		}
	}
	return OK;
}

void output_matrix(const matrix_t &matrix)
{
    printf("MATRIX:\n");
    for (int i = 0; i < matrix.rows; i++)
    {
        printf("\t");
        for (int j = 0; j < matrix.columns; j++)
        {
            printf("%lf ", matrix.pointers[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}