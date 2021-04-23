#ifndef TRANSFORM_SETTINGS_H
#define TRANSFORM_SETTINGS_H

#include "../../interface/inc/MyGraphicsItemGroup.hpp"
#include "../inc/errors.hpp"


#define DOWNLOAD 1
#define TRANSFORM 2
#define DRAW 3
#define EXIT 4
#define UNKNOWN_COMMAND 5

// TRANSFORM_SETTINGS
#define TRANSFER 6
#define ROTATE 7
#define SCALE 8


struct transform_settings_t
{
    double x;
    double y;
    double z;
    int command;
};

union command_settings_t
{
    transform_settings_t transform_settings;
    MyGraphicsItemGroup *picture;
    char *filename;
};

struct task_settings_t
{
    int command;
    command_settings_t command_settings;
};

int task_main(task_settings_t settings);


void output_transform_settings(const transform_settings_t &settings);
void output_task_settings(const task_settings_t &settings);

#endif