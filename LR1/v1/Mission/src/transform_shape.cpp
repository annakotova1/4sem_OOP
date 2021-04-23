#include "../inc/transform_shape.hpp"

int transform_shape(all_points &object, const command_parametres &settings)
{
    my_matrix transform_matrix, coordinate_matrix, result;
    int rc;
    rc = make_transform_matrixes(transform_matrix, settings);
    if (rc != OK)
        return rc;
    for (list_points_node *cur = object.head;cur;cur = cur->next)
    {
        rc = make_coordinates_matrixes(coordinate_matrix, cur->data.coordinates);
        if (rc != OK)
            break;
        rc = multiplicate_matrixes(result, coordinate_matrix, transform_matrix);
        if (rc != OK)
            break;
        rc = make_coordinates_from_matrixes(cur->data.coordinates, result);
        if (rc != OK)
            break;
    }
    delete_matrix(transform_matrix);
    delete_matrix(coordinate_matrix);
    delete_matrix(result);

    return OK;
}

