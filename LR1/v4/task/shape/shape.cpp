#include "shape.hpp"

int download_shape(shape_t &new_shape, char *filename)
{
    print_line();
    printf("DOWNLOAD SHAPE\n");
    print_line();

    int rc = OK;
    FILE *file = fopen(filename, "r");
    if (!file)
        return ERR_FILE_NO;

    list_point_node_t *new_points = NULL;
    list_edge_node_t *new_edges = NULL;

    printf("download points list\n");
    
    rc = download_list_point(&new_points, file);

    printf("error code = %d\n", rc);

    if (rc == OK)
    {
        fscanf(file, "-----\n");
    }

    if (rc == OK)
    {
        printf("download edges list\n");
        rc = download_list_edge(&new_edges, file);
        printf("error code = %d\n", rc);

        if (rc == OK)
        {
            delete_list_point(&new_shape.point);
            delete_list_edge(&new_shape.edge);
            new_shape.point = new_points;
            new_shape.edge = new_edges;
        }
        else
        {
            delete_list_point(&new_points);
            //delete_list_edge(&new_edges);
        }
    }
    fclose(file);
    printf("\nresult point_list:\n");
    output_list_point(new_shape.point);
    printf("\nresult edge_list:\n");
    output_list_edge(new_shape.edge);
    
    print_line();
    printf("END DOWNLOAD SHAPE\n");
    print_line();
    return OK;
}

int transform_shape(shape_t &shape, const transform_settings_t &settings)
{
    print_line();
    printf("START TRANSFORM SHAPE\n");
    print_line();
    int rc = OK;
    dot_t center_operation;
    rc = get_shape_center(center_operation, shape.point);
    if (rc != OK)
        return rc;
    output_dot(center_operation);
    output_transform_settings(settings);

    matrix_t transform_matrix;
    rc = make_transform_matrix(transform_matrix, settings, center_operation);
    if (rc != OK)
        return rc;
    printf("make matrix\n");

    output_matrix(transform_matrix);

    rc = transform_list_point((shape.point), transform_matrix); 
    mem_delete_matrix(transform_matrix);

    print_line();
    printf("END TRANSFORM SHAPE\n");
    print_line();
    
    return OK;
}

int draw_shape(shape_t &shape, const command_settings_t &settings)
{
    print_line();
    printf("START DRAW SHAPE\n");
    print_line();
    //output_list_point(shape.point);
    //output_list_edge(shape.edge);
    int rc = OK;
    rc = draw_list_edge((shape.edge), (shape.point), settings);       
    print_line();
    printf("END DRAW SHAPE\n");
    print_line();
    
    return rc;
}

shape_t &init_shape()
{
    static shape_t shape;
    shape.point = NULL;
    shape.edge = NULL;
    return shape;
}

void delete_shape(shape_t &shape)
{
    delete_list_point(&shape.point);
    delete_list_edge(&shape.edge);
}

void output_shape(shape_t &shape)
{
    output_list_point(shape.point);
    output_list_edge(shape.edge);
}