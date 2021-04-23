#ifndef MYDOMENSINTERACTION_H
#define MYDONENSINTERACTION_H

#include "../inc/my_points_list.hpp"
#include "download_points.hpp"
#include "transform_shape.hpp"
#include "draw_picture.hpp"

// COMMANDS
#define DOWNLOAD 4
#define TRANSFORM 5
#define DRAW 6

// Interaction of two domains
struct domens_interaction
{
	QGraphicsItemGroup *group;
	int command;
	command_parametres settings;
	char *filename;
};

int mission_main(domens_interaction &data);


#endif