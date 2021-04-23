#ifndef STRUCTS_H
#define STRUCTS_H

#include <QGraphicsItemGroup>

// ERROR CODES
#define OK 0
#define ERR_NO_FILE 1
#define ERR_BAD_FILE 2
#define ERR_UNKNOWEN_COMMAND 3

// COMMANDS
#define DOWNLOAD 4
#define TRANSFORM 5
#define DRAW 6

// GEOMETRY
struct my_point
{
	double x;
	double y;
	double z;
};

struct my_vector_coordinates
{
	double x;
	double y;
	double z;
};

struct my_vector
{
	my_point start;
	my_point end;
};

// MATRIXES
struct my_array
{
	double *data;
	int size;
};
struct my_matrix
{
	double **pointers;
	int rows;
	int columns;
};

// CAMERA
struct my_camera
{
	my_vector leftUpperConner;
	my_vector rightDownConner;
};

// LISTS NODES
struct list_lines_node
{
	char name;
	list_lines_node *next;
};

struct shape_point // Point with conections
{
	char name;
	my_point coordinates;
	list_lines_node *lineHead;
};

struct list_points_node
{
	shape_point *data;
	list_points_node *next;
};

struct all_points
{
	list_points_node *head;
	my_array data;
};

// COMMAND SETTINGS FOR TRANSFORM
struct command_parametres
{
	double x;
	double y;
	double z;
	double operation;
};

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