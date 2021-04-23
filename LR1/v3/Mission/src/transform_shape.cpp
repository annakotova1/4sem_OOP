#include "../inc/transform_shape.hpp"

int transform_shape(all_points &object, const command_parametres &settings)
{
    my_matrix transform_matrix, coordinate_matrix, result;
    printf("start\n");
    int rc;
    rc = make_transform_matrixes(transform_matrix, settings);
    printf("start1\n");
    if (rc != OK)
        return rc;
    for (list_points_node *cur = object.head;cur;cur = cur->next)
    {
        rc = make_coordinates_matrixes(coordinate_matrix, cur->data.coordinates);
    printf("start2\n");
        if (rc != OK)
            break;
    printf("start3\n");
        rc = multiplicate_matrixes(result, coordinate_matrix, transform_matrix);
        if (rc != OK)
            break;
    printf("start4\n");
        rc = make_coordinates_from_matrixes(cur->data.coordinates, result);
        if (rc != OK)
            break;
    }
    printf("start5\n");
    delete_matrix(transform_matrix);
    delete_matrix(coordinate_matrix);
    delete_matrix(result);
    printf("end\n");

    return OK;
}

