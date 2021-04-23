#include "point.hpp"

int compare_points_id(const point_t &p, const int &id)
{
    if (id == p.id)
        return TRUE;
    return FALSE;
}

int download_point(point_t &result, FILE *file)
{
    char sc;
    if (!file)
        return ERR_ARGS;
    int rc = fscanf(file, "%d, ", &result.id);
    if (rc != 1)
        return END_READ;
    printf("READ ID\n");
    rc = fscanf(file, "%lf %lf %lf\n", &result.dot.x, &result.dot.y, &result.dot.z);
    output_point(result);
    if (rc != 3)
        return ERR_FILE_BAD;
    rc = fscanf(file, "%c", &sc);
    if (rc != 1 || sc != ';')
        return ERR_FILE_BAD;
    return OK;
}

int convert_matrix_to_point(point_t &center, const matrix_t &matrix)
{
    if (matrix.columns != 4 && matrix.rows != 1)
        return ERR_ARGS;
    center.dot.x = matrix.pointers[0][0];
    center.dot.y = matrix.pointers[0][1];
    center.dot.z = matrix.pointers[0][2];
    return OK;
}

int transform_point(point_t &result, const matrix_t &matrix)
{
    matrix_t start_coordinates, end_coordinates;
    int rc = mem_create_matrix(start_coordinates, 1, 4);
    if (rc != OK)
        return rc;
    start_coordinates.pointers[0][0] = result.dot.x;
    start_coordinates.pointers[0][1] = result.dot.y;
    start_coordinates.pointers[0][2] = result.dot.z;
    start_coordinates.pointers[0][3] = 1;
    output_matrix(start_coordinates);

    output_matrix(matrix);
    if (rc == OK)
        rc = mem_multiplicate_matrix(end_coordinates, start_coordinates, matrix);
    if (rc == OK)
    {
        rc = convert_matrix_to_point(result, end_coordinates);
        output_dot(result.dot);
        output_matrix(end_coordinates);
        mem_delete_matrix(end_coordinates);
    }

    mem_delete_matrix(start_coordinates);
    
    return rc;
}

void output_point(point_t point)
{
    printf("\t\tPoint id = %d:", point.id);
    output_dot(point.dot);
}

int get_id(const point_t &point)
{
    return point.id;
}