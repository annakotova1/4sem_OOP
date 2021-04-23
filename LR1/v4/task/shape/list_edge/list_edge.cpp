#include "list_edge.hpp"

int create_edge_node(list_edge_node_t **new_node, const edge_t &data)
{
    *new_node = (list_edge_node_t *)calloc(1, sizeof(list_edge_node_t));
    if (!*new_node)
        return ERR_MEMORY;
        
    (*new_node)->data = data;
    (*new_node)->next = NULL;
    return OK;
}

int delete_edge_node(list_edge_node_t **node, edge_t &p)
{
    if (!node)
        return ERR_ARGS;
    
    p = (*node)->data;
    free(*node);
    *node = NULL;
    return OK; 
}
int add_edge_node(list_edge_node_t **head, list_edge_node_t *new_node)
{
    if (!head)
        return ERR_ARGS;

    if (!*head)
    {
        *head = new_node;
        return OK;
    }
    list_edge_node_t *cur = *head;
    for (; cur->next; cur = cur->next);
    cur->next = new_node;
    return OK;
}

int delete_list_edge(list_edge_node_t **head)
{
    if (!head)
        return ERR_ARGS;
    if (!*head)
        return OK;

    list_edge_node_t *next = (*head)->next;
    for (list_edge_node_t *cur = *head; next; next = next->next)
    {
        free(cur);
        cur = next;
    }
    free(next);
    return OK;
}

int apply_for_each_edge(list_edge_node_t **head, int (*func)(edge_t))
{
    int rc = OK;
    for (list_edge_node_t *cur = *head; cur && (rc == OK); cur = cur->next)
    {
        rc = func(cur->data);
    }
    return rc;
}

int download_list_node(list_edge_node_t **head, FILE *file)
{
    list_edge_node_t *new_node;
    edge_t edge;
    int rc = download_edge(edge, file);
    if (rc == OK)
    {
        rc = create_edge_node(&new_node, edge);
        if (rc == OK)
        {
            rc = add_edge_node(head, new_node);
        }
    }
    return rc;
}

int download_list_edge(list_edge_node_t **head, FILE *file)
{
    //print_line();
    //print_line();
    int rc = 0;
    while (rc == OK)
    {
        rc = download_list_node(head, file);
    }
    if (rc == END_READ)
        rc = OK;
    return rc;
}

int find_edge_dots(dot_t &p1, dot_t &p2, list_point_node_t *points, const edge_t &edge)
{
    int rc = find_point_by_id(points, p1, edge.id1);
    if (rc == OK)
        rc = find_point_by_id(points, p2, edge.id2);
    return rc;
}

int draw_list_edge(list_edge_node_t *head, list_point_node_t *points, const command_settings_t &settings)
{
    dot_t p1, p2;
    int rc = OK;
    for (list_edge_node_t *cur = head; cur && rc == OK; cur = cur->next)
    {
        find_edge_dots(p1, p2, points, cur->data);
        if (rc == OK)
            rc = draw_edge(p1, p2, settings);
    }
    return rc;
}

void output_list_edge(list_edge_node_t *head)
{
    for (list_edge_node_t *cur = head; cur; cur = cur->next)
    {
        output_edge(cur->data);
    }
}