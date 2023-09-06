#ifndef TEMPLATEINTERACTION_H
#define TEMPLATEINTERACTION_H

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
// OPERATIONS
#define TRANSFER 1
#define ROTATE 2
#define SCALE 3


// GEOMETRY
struct myPoint
{
	double x;
	double y;
	double z;
};

struct myVectorCoordinates
{
	double x;
	double y;
	double z;
};

struct myVector
{
	myPoint start;
	myPoint end;
};

// MATRIXES
struct myArray
{
	double *data;
	int size;
};
struct myMatrix
{
	double **pointers;
	int rows;
	int columns;
};

// CAMERA
struct myCamera
{
	myVector leftUpperConner;
	myVector rightDownConner;
};

// LISTS NODES
struct listLinesNode
{
	myPoint *data;
	listLinesNode *next;
};

struct shapePoint // Point with conections
{
	myPoint coordinates;
	listLinesNode *lineHead;
};

struct listPointsNode
{
	shapePoint *data;
	listPointsNode *next;
};

struct allPoints
{
	listPointsNode *head;
	myArray data;
};

// COMMAND SETTINGS FOR TRANSFORM
struct commandParametres
{
	double x;
	double y;
	double z;
	double operation;
};

// Interaction of two domains
struct domensInteraction
{
	QGraphicsItemGroup *group;
	allPoints object;
	myCamera &camera;
	int command;
	commandParametres settings;
	char *filename;
};


#endif