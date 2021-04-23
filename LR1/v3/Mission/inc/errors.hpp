#ifndef ERRORS_H
#define ERRORS_H

// ERROR CODES
#define OK 0
#define ERR_NO_FILE 1
#define ERR_BAD_FILE 2
#define ERR_UNKNOWEN_COMMAND 3
#define ERR_MEMORY 4
#define ERR_BAD_PARAMETRES 5
#define ERR_MATRIX_MULTI 6
#define ERR_BAD_MATRIX 7
#define ERR_BAD_FILE_UNKNOWN_POINT 8
#define ERR_BAD_FILE_SIMILAR_POINTS 9

#define END_READ 10


struct my_point
{
	double x;
	double y;
	double z;
};

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