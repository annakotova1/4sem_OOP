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
    printf("add_point\n");
    output_list_point(*head);
    list_point_node_t *cur = *head;
    for (; cur->next; cur = cur->next);
    cur->next = new_node;
    return OK;
}

int delete_list_point(list_point_node_t **head)
{
    if (!head)
        return ERR_ARGS;
    if (!*head)
        return OK;

    list_point_node_t *next = (*head)->next;
    for (list_point_node_t *cur = *head; next; next = next->next)
    {
        free(cur);
        cur = next;
    }
    free(next);
    return OK;
}

int apply_for_each_point(list_point_node_t **head, int (*func)(point_t))
{
    int rc = OK;
    for (list_point_node_t *cur = *head; cur && (rc == OK); cur = cur->next)
    {
        rc = func(cur->data);
    }
    return rc;
}

int find_point_by_id(list_point_node_t *head, dot_t &result, const int &id)
{
    if (!head)
        return ERR_ARGS;
    int rc = ERR_ARGS;
    for (list_point_node_t *cur = head; cur && (rc == ERR_ARGS); cur = cur->next)
    {
        //output_point(cur->data);
        //printf("expected id = %d\n", id);
        if (compare_points_id(cur->data, id) == OK)
        {
            result = cur->data.dot;
            rc = OK;
        }
    }
    return rc;
}

int get_x_center(dot_t &center, list_point_node_t *head)
{
    int x_exist = FALSE;
    int min = 0, max = 0;
    for (list_point_node_t *cur = head; cur; cur = cur->next)
    {
        if (x_exist == FALSE)
        {
            min = cur->data.dot.x;
            max = cur->data.dot.x;
            x_exist = TRUE;
        }
        else if (cur->data.dot.x < min)
        {
            min = cur->data.dot.x;
        }
        else if (cur->data.dot.x > max)
        {
            max = cur->data.dot.x;
        }
    }
    center.x = (max - min)/2 + min;
    return OK;
}

int get_y_center(dot_t &center, list_point_node_t *head)
{
    int y_exist = FALSE;
    int min = 0, max = 0;
    for (list_point_node_t *cur = head; cur; cur = cur->next)
    {
        if (y_exist == FALSE)
        {
            min = cur->data.dot.y;
            max = cur->data.dot.y;
            y_exist = TRUE;
        }
        else if (cur->data.dot.y < min)
        {
            min = cur->data.dot.y;
        }
        else if (cur->data.dot.y > max)
        {
            max = cur->data.dot.y;
        }
    }
    center.y = (max - min)/2 + min;
    return OK;
}
int get_z_center(dot_t &center, list_point_node_t *head)
{
    int z_exist = FALSE;
    int min = 0, max = 0;
    for (list_point_node_t *cur = head; cur; cur = cur->next)
    {
        if (z_exist == FALSE)
        {
            min = cur->data.dot.z;
            max = cur->data.dot.z;
            z_exist = TRUE;
        }
        else if (cur->data.dot.z < min)
        {
            min = cur->data.dot.z;
        }
        else if (cur->data.dot.z > max)
        {
            max = cur->data.dot.z + min;
        }
    }
    center.z = (max - min)/2;
    return OK;
}
int get_shape_center(dot_t &center, list_point_node_t *head)
{
    int rc = get_x_center(center, head);
    if (rc == OK)
        rc = get_y_center(center, head);
    if (rc == OK)
        rc = get_z_center(center, head);
    return rc;
}

int download_list_point(list_point_node_t **head, FILE *file)
{
    //print_line();
    //printf("start download list points\n");
    int rc = OK;
    list_point_node_t *new_node;
    point_t point;
    dot_t buff;
    while (rc == OK)
    {
        rc = download_point(point, file);
        //printf("rc = %d\n", rc);
        if (rc == OK)
        {
            //printf("new point:");
            //output_point(point);
            rc = find_point_by_id(*head, buff, point.id);
            if (rc == OK)
                rc = ERR_FILE_BAD; 
            else
                rc = OK;
            if (rc == OK)
            {
                rc = create_point_node(&new_node, point);
                //printf("error_code of read point: %d\n", rc);
                if (rc == OK)
                {
                    rc = add_point_node(head, new_node);    
                    //printf("result points list\n");
                    //output_list_point(*head);
                }
            }
        }
    }
    //printf("end download list points\n");
    //print_line();
    if (rc == END_READ)
        rc = OK;
    return rc;
}

int transform_list_point(list_point_node_t *head, const matrix_t &transform_matrix)
{
    int rc = OK;
    printf("start transform list point\n");
    for (list_point_node_t *cur = head; cur && rc == OK; cur = cur->next)
    {
        printf("start point\n");
        output_point(cur->data);
        rc = transform_point(cur->data, transform_matrix);
        output_point(cur->data);
        printf("end point\n");
    }
    printf("end transform list point\n");
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