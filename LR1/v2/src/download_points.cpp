#include "../inc/download_points.hpp"

int read_point(shape_point &p, FILE *file)
{
    int rc = fscanf(file, "%c %lf %lf %lf", p.name, p.coordinates.x, p.coordinates.y, p.coordinates.z);
    if (rc == 0)
    {
        fscanf(file, "\n");
        return END_READ;
    }
    if (rc != 4)
        return ERR_BAD_FILE;
    p.line_head = NULL;
    return OK;
}
int get_point_by_name(shape_point **point, list_points_node *head, const char &name)
{
    point = NULL;
    for (list_points_node *cur = head; cur; cur = cur->next)
    {
        if (cur->data.name == name)
        {
            *point = &(cur->data);
            break;
        }
    }
    return ERR_BAD_FILE_UNKNOWN_POINT;
}
int read_line(list_points_node *head, FILE *file)
{
    char start, end;
    shape_point *p_start, *p_end;
    int rc;

    rc = fscanf(file, "%c %c", start, end);
    if (rc < 1)
        return END_READ;
    if (rc != 2)
        return ERR_BAD_FILE;
    
    rc = get_point_by_name(&p_start, head, start);
    if (rc != OK)
        return rc;
    rc = get_point_by_name(&p_end, head, start);
    if (rc != OK)
        return rc;

    list_lines_node *node;
    rc = create_lines_node(&node, p_end);
    if (rc != OK)
        return rc;
    add_lines_node(&(p_start->line_head), node);
    if (rc != OK)
    {
        delete_lines_node(&node);
        return rc;
    }
    return OK;
}

int check_point(const shape_point &point, list_points_node *head)
{
    for (list_points_node *cur = head; cur; cur = cur->next)
    {
        if (cur->data.name == point.name)
            return ERR_BAD_FILE_SIMILAR_POINTS;
        if (cur->data.coordinates.x == point.coordinates.x)
            return ERR_BAD_FILE_SIMILAR_POINTS;
        if (cur->data.coordinates.y == point.coordinates.y)
            return ERR_BAD_FILE_SIMILAR_POINTS;
        if (cur->data.coordinates.z == point.coordinates.z)
            return ERR_BAD_FILE_SIMILAR_POINTS;
    }
    return OK;
}

int read_file(list_points_node **head, char *filename)
{
    *head = NULL;
    int rc = OK;
    shape_point new_point;
    list_points_node *node = NULL;

    FILE *file = fopen(filename, "r");

    rc = read_point(new_point, file);
    while (rc == OK)
    {
        rc = check_point(new_point, *head);
        if (rc == OK)
        {
            rc = create_points_node(&node, new_point);
            if (rc == OK)
            {
                rc = add_points_node(head, node);
                if (rc == OK)
                    rc = read_point(new_point, file);
            }
        }
    }
    if (rc == END_READ)
    {
        rc = check_point(new_point, *head);
        if (rc == OK)
        {
            rc = create_points_node(&node, new_point);
            if (rc == OK)
                rc = add_points_node(head, node);
        }
    }
    if (rc != OK)
    {
        delete_points_list(head);
        return rc;
    }
    rc = OK;
    while(rc == OK)
    {
        rc = read_line(*head, file);
    }
    fclose(file);
    if (rc == END_READ)
        rc = OK;
    return rc;
}

int downloadPoints(all_points &object, char *filename)
{
    list_points_node *new_head = NULL;
    int rc;
    rc = read_file(&new_head, filename); 
    if (rc != OK)
    {
        return rc;
    }
    delete_points_list(&object.head);
    object.head = new_head;
    return OK;
}