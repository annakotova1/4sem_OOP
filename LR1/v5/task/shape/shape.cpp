#include "shape.hpp"

void buffer_init(shape_t &shape)
{
    shape.points = NULL;
    shape.edges = NULL;
}

int download_buffer(shape_t &buffer, FILE *file)
{
    int rc = download_list_point(&buffer.points, file);

    if (rc == OK)
    {
        fscanf(file, "-----\n"); // обертка

        rc = download_list_edge(&buffer.edges, file);
        if (rc != OK)
            delete_list_point(&buffer.points);
    }

    return rc;
}
int file_open(FILE *file, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return ERR_FILE_NO;
    return OK;
}

int download_shape(shape_t &shape, char *filename)
{
    FILE *file;
    int rc = file_open(file, filename);

    shape_t buffer;
    buffer_init(buffer);

    if (rc == OK)
        rc = download_buffer(buffer, file);
    fclose(file);

    if (rc == OK)
    {
        delete_shape(shape);
        shape = buffer;
    }
    return OK;
}

int transform_shape(shape_t &shape, const transform_settings_t &settings)
{
    if (!shape.points)
        return ERR_NO_SHAPE;

    dot_t center_operation;
    matrix_t transform_matrix;

    int rc = get_shape_center(center_operation, shape.points);
    
    if (rc == OK)
        rc = make_transform_matrix(transform_matrix, settings, center_operation);
    
    if (rc == OK)
    {
        rc = transform_list_point((shape.points), transform_matrix); 
        mem_delete_matrix(transform_matrix);
    }
    return rc;
}

int draw_shape(shape_t &shape, const command_settings_t &settings)
{
    if (!shape.points)
        return ERR_NO_SHAPE;
    int rc = draw_list_edge((shape.edges), (shape.points), settings);
    return rc;
}

shape_t &init_shape()
{
    static shape_t shape;
    shape.points = NULL;
    shape.edges = NULL;
    return shape;
}

int exit(shape_t &shape)
{
    if (!shape.points)
        return ERR_NO_SHAPE;
    
    delete_shape(shape);
    return OK;
}

void delete_shape(shape_t &shape)
{
    delete_list_point(&shape.points);
    delete_list_edge(&shape.edges);
}

void output_shape(shape_t &shape)
{
    output_list_point(shape.points);
    output_list_edge(shape.edges);
}