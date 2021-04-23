#include "../inc/my_points_list.hpp"
all_points &init()
{
	static all_points point;
	point.head = NULL;
	return point;
}
int create_points_node(list_points_node **node, shape_point &data)
{
	*node = (list_points_node *)calloc(1, sizeof(list_points_node));
	if (!*node)
	return ERR_MEMORY;
	(*node)->data = data;
	(*node)->next = NULL;
	return OK;
}

int add_points_node(list_points_node **head, list_points_node *node)
{
	if (!node)
		return ERR_BAD_PARAMETRES;
	if (!*head)
	{
		*head = node;
		return OK;
	}
	list_points_node *cur = *head;
	for (;cur->next; cur = cur->next);
	cur->next = node;
	return OK;
}

int delete_points_node(list_points_node **node)
{
	free(*node);
	*node = NULL;
	return OK;
}

int delete_points_list(list_points_node **head)
{
	if (!*head)
		return OK;
	list_points_node *cur = *head;
	list_points_node *next = (*head)->next;
	for (;next->next;)
	{
		delete_points_node(&cur);
		cur = next;
		next = next->next;
	}
	delete_points_node(&cur);
	return OK;
}
