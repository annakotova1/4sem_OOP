#ifndef MYDOMENSINTERACTION_H
#define MYDONENSINTERACTION_H

#include <QGraphicsItemGroup>

// COMMANDS
#define DOWNLOAD 4
#define TRANSFORM 5
#define DRAW 6

// Interaction of two domains
struct domens_interaction
{
	QGraphicsItemGroup *group;
	all_points object;
	my_camera &camera;
	int command;
	command_parametres settings;
	char *filename;
};


#endif