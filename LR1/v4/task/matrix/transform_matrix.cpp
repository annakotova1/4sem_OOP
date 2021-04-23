#include "transform_matrix.hpp"
 
int fill_transfer(matrix_t &matrix, transform_settings_t settings)
{
    int rc = mem_make_single_matrix(matrix, MATRIX_SIZE, MATRIX_SIZE);
    if (rc != OK)
        return rc;

    matrix.pointers[3][0] = settings.x;
	matrix.pointers[3][1] = settings.y;
	matrix.pointers[3][2] = settings.z;
    return OK;
}
int fill_scale(matrix_t &matrix, transform_settings_t settings)
{
    int rc = mem_make_single_matrix(matrix, MATRIX_SIZE, MATRIX_SIZE);
    if (rc != OK)
        return rc;

    matrix.pointers[0][0] = settings.x;
	matrix.pointers[1][1] = settings.y;
	matrix.pointers[2][2] = settings.z;
    return OK;
}

void add_center(matrix_t &matrix, const dot_t &center)
{
    matrix.pointers[3][0] += center.x;
    matrix.pointers[3][1] += center.y;
    matrix.pointers[3][2] += center.z;
}

void sub_center(matrix_t &matrix, const dot_t &center)
{
    matrix.pointers[3][0] -= center.x;
    matrix.pointers[3][1] -= center.y;
    matrix.pointers[3][2] -= center.z;
}

int make_transfer_matrix(matrix_t &matrix, transform_settings_t settings)
{
    int rc = fill_transfer(matrix, settings);
    return rc;
}

int make_rotate_matrix(matrix_t &matrix, transform_settings_t settings, const dot_t &center)
{
    matrix_t dop_matrix, ans;
    int rc = mem_make_single_matrix(dop_matrix, MATRIX_SIZE, MATRIX_SIZE);
    sub_center(dop_matrix, center);

    rc = fill_rotate(matrix, settings);
    if (rc == OK)
        add_center(matrix, center);

    if (rc == OK)
        rc = mem_multiplicate_matrix(ans, dop_matrix, matrix);
    if (rc == OK)
    {
        mem_delete_matrix(matrix);
        mem_copy_matrix(matrix, ans);
    }

    mem_delete_matrix(dop_matrix);
    return rc;
}
int make_scale_matrix(matrix_t &matrix, transform_settings_t settings, const dot_t &center)
{
    matrix_t dop_matrix, ans;
    int rc = mem_make_single_matrix(dop_matrix, MATRIX_SIZE, MATRIX_SIZE);
    if (rc != OK)
        return rc;
    sub_center(dop_matrix, center);
    rc = fill_scale(matrix, settings);
    if (rc == OK)
        add_center(matrix, center);

    if (rc == OK)
        rc = mem_multiplicate_matrix(ans, dop_matrix, matrix);
    if (rc == OK)
    {
        mem_delete_matrix(matrix);
        mem_copy_matrix(matrix, ans);
    }
   
    mem_delete_matrix(dop_matrix);
    mem_copy_matrix(matrix, ans);
    return rc;
}
int make_transform_matrix(matrix_t &matrix, transform_settings_t settings, const dot_t &center)
{
    int rc;
    switch (settings.command)
    {
        case TRANSFER:
            rc = make_transfer_matrix(matrix, settings);
            break;
        case ROTATE:
            rc = make_rotate_matrix(matrix, settings, center);
            break;
        case SCALE:
            rc = make_scale_matrix(matrix, settings, center);
            break;
        default:
            rc = ERR_UNKNOWN_CHOISE;
    }
    output_matrix(matrix);
    printf("rc = %d\n", rc);
    output_dot(center);
    //if (rc == OK)
    //    rc = add_center(matrix, center);
    return rc;
}