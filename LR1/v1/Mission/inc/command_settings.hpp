#ifndef COMMANDSETTINGS_H
#define COMMANDSETTINGS_H

// OPERATIONS
#define TRANSFER 1
#define ROTATE 2
#define SCALE 3

struct command_parametres
{
	double x;
	double y;
	double z;
	int operation;
};

#endif