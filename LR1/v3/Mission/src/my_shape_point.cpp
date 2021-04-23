#include "../inc/my_shape_point.hpp"

int create_lines_node(list_lines_node **node, shape_point *data)
{
	*node = (list_lines_node *)calloc(1, sizeof(list_lines_node));
	if (!*node)
	return ERR_MEMORY;
	(*node)->adjacent_point = data;
	(*node)->next = NULL;
	return OK;
}

int add_lines_node(list_lines_node **head, list_lines_node *node)
{
	if (!node)
		return ERR_BAD_PARAMETRES;
	if (!*head)
	{
		*head = node;
		return OK;
	}
	list_lines_node *cur = *head;
	for (;cur->next; cur = cur->next);
	cur->next = node;
	return OK;
}

int delete_lines_node(list_lines_node **node)
{
	free(*node);
	*node = NULL;
	return OK;
}

int delete_lines_list(list_lines_node **head)
{
	if (!*head)
		return OK;
	list_lines_node *cur = *head;
	list_lines_node *next = (*head)->next;
	for (;next->next;)
	{
		delete_lines_node(&cur);
		cur = next;
		next = next->next;
	}
	delete_lines_node(&cur);
	return OK;
}
