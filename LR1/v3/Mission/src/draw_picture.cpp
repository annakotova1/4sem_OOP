#include "../inc/draw_picture.hpp"

void draw_line(shape_point &point1, shape_point &point2, QGraphicsItemGroup *group)
{
	QGraphicsLineItem *line = new QGraphicsLineItem(point1.coordinates.x, point1.coordinates.y, 
		point2.coordinates.x, point2.coordinates.y);
	group->addToGroup(line);
}

int draw_picture(all_points &object, QGraphicsItemGroup *group)
{
	for (list_points_node *cur1 = object.head; cur1; cur1 = cur1->next)
	{
		for (list_lines_node *cur2 = cur1->data.line_head; cur2; cur2 = cur2->next)
		{
			draw_line(cur1->data, (*cur2->adjacent_point), group);
		}
	}
	return OK;
}
