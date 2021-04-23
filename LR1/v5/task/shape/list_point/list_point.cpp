#include "list_point.hpp"

int create_point_node(list_point_node_t **new_node, const point_t &data)
{
    *new_node = (list_point_node_t *)calloc(1, sizeof(list_point_node_t));
    if (!*new_node)
        return ERR_MEMORY;
        
    (*new_node)->data = data;
    (*new_node)->next = NULL;
    return OK;
}

int delete_point_node(list_point_node_t **node, point_t &p)
{
    if (!node)
        return ERR_ARGS;
    
    p = (*node)->data;
    free(*node);
    *node = NULL;
    return OK; 
}
int add_point_node(list_point_node_t **head, list_point_node_t *new_node)
{
    if (!head)
        return ERR_ARGS;

    if (!*head)
    {
        *head = new_node;
        return OK;
    }
    list_point_node_t *cur = *head;
    for (; cur->next; cur = cur->next);
    cur->next = new_node;
    return OK;
}

int delete_point_node(list_point_node_t **head)
{
    if (!head)
        return ERR_ARGS;

    if (!*head)
        return OK;

    list_point_node_t *node;
    node = (*head)->next;
    free(head);
    *head = node;
    return OK;
}

int delete_list_point(list_point_node_t **head)
{
    if (!head)
        return ERR_ARGS;
    if (!*head)
        return OK;
    int rc;
    for (; *head && rc == OK;)
    {
        rc = delete_point_node(head);
    }
    return OK;
}

int apply_for_each_point(list_point_node_t **head, int (*func)(point_t))
{
    int rc = OK;
    for (list_point_node_t *cur = *head; cur && (rc == OK); cur = cur->next)
        rc = func(cur->data);
    
    return rc;
}

int find_point_by_id(list_point_node_t *head, dot_t &result, const int &id)
{
    if (!head)
        return ERR_ARGS;
    int rc = ERR_ARGS;
    for (list_point_node_t *cur = head; cur && (rc == ERR_ARGS); cur = cur->next)
    {
        if (compare_points_id(cur->data, id) == OK)
            rc = get_point_dot(result, cur->data);
    }
    return rc;
}

int get_coordinate_center(dot_t &center, list_point_node_t *head, const int &coordinate)
{
    int x_exist = FALSE;
    int min = 0, max = 0, cur_coord, rc;
    for (list_point_node_t *cur = head; cur; cur = cur->next)
    {
        rc = get_point_coordinate(cur_coord, cur->data, coordinate);
        if (rc == OK)
        {   if (x_exist == FALSE)
            {
                min = cur_coord;
                max = cur_coord;
                x_exist = TRUE;
            }
            else if (cur_coord < min)
                min = cur_coord;
            else if (cur_coord > max)
                max = cur_coord;
        }
    }
    if (rc == OK)
        center.coord[coordinate] = (max - min)/2 + min;
    return OK;
}
int get_shape_center(dot_t &center, list_point_node_t *head)
{
    int rc = get_coordinate_center(center, head, MY_X);
    if (rc == OK)
        rc = get_coordinate_center(center, head, MY_Y);
    if (rc == OK)
        rc = get_coordinate_center(center, head, MY_Z);
    return rc;
}

int check_new_point(const point_t& point, list_point_node_t **head)
{
    dot_t buff;
    int rc = find_point_by_id(*head, buff, point.id);
    if (rc == OK)
        return ERR_FILE_BAD; 
    else
        return OK;
}
int download_point_node(list_point_node_t **head, FILE *file)
{
    point_t point;
    list_point_node_t *new_node;
    int rc = download_point(point, file);
    if (rc == OK)
        rc = check_new_point(point, head);
    if (rc == OK)
        rc = create_point_node(&new_node, point);
    if (rc == OK)
        rc = add_point_node(head, new_node);
    return rc;
}
int download_list_point(list_point_node_t **head, FILE *file)
{
    int rc = OK;
    while (rc == OK)
        rc = download_point_node(head, file);

    if (rc == END_READ)
        rc = OK;
    return rc;
}

int transform_list_point(list_point_node_t *head, const matrix_t &transform_matrix)
{
    int rc = OK;
    for (list_point_node_t *cur = head; cur && rc == OK; cur = cur->next)
        rc = transform_point(cur->data, transform_matrix);

    return rc;
}

void output_list_point(list_point_node_t *head)
{
    printf("start list points output\n");
    for (list_point_node_t *cur = head; cur; cur = cur->next)
    {
        output_point(cur->data);
    }
}