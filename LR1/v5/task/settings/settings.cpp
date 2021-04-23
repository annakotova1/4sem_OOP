#include "settings.hpp"

int make_transform_settings(transform_settings_t &settings, const int &command, const int &x, const int &y, const int &z)
{
    settings.command = command;
    settings.x = x;
    settings.y = y;
    settings.z = z;
    return OK;
}

void output_transform_settings(const transform_settings_t &settings)
{
    printf("\t\tTransform settings:\n");
    printf("\t\t\tcommnad: ");
    switch (settings.command)
    {
        case TRANSFER:
            printf("transfer\n");
            break;
        case ROTATE:
            printf("rotate\n");
            break;
        case SCALE:
            printf("scale\n");
            break;
        default:
            printf("unknow command\n");
    }
}

void output_task_settings(const task_settings_t &settings)
{
    printf("Task settings:\n");
    printf("\tcommnad: ");
    switch (settings.command)
    {
        case DOWNLOAD:
            printf("download\n");
            printf("\t dop parameter - filename: %s\n", settings.command_settings.filename);
            break;
        case TRANSFORM:
            printf("transform\n");
            printf("\t dop parameter - transform_settings\n");
            output_transform_settings(settings.command_settings.transform_settings);
            break;
        case DRAW:
            printf("draw\n");
            printf("\t dop parameter - MyGraphicsItemGroup\n");
            break;
        case EXIT:
            printf("exit\n");
            printf("\t dop parameter - nothing");
            break;
        default:
            printf("unknow command\n");
    }
}

char *get_download_settings(const task_settings_t &settings)
{
    return settings.command_settings.filename;
}

const transform_settings_t get_transform_settings(const task_settings_t &settings)
{
    return settings.command_settings.transform_settings;
}

MyGraphicsItemGroup *get_draw_settings(const task_settings_t &settings)
{
    return settings.command_settings.picture;
}