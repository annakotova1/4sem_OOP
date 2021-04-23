#include "../shape/shape.hpp"
#include "../settings/settings.hpp"

int task_main(task_settings_t settings)
{
    int rc;
    static shape_t shape = init_shape();
    switch(settings.command)
    {
        case DOWNLOAD:
            rc = download_shape(shape, settings.command_settings.filename);
            printf("rc = %d\n", rc); 
            break;
        case TRANSFORM:
            if (shape.point)
                rc = transform_shape(shape, settings.command_settings.transform_settings);
            else 
                rc = ERR_NO_SHAPE;
            break;
        case DRAW:
            if (shape.point)
                rc = draw_shape(shape, settings.command_settings);
            else 
                rc = ERR_NO_SHAPE;
            break;
        case EXIT:
            if (shape.point)
            {
                rc = OK;
                delete_shape(shape);
            }
            else 
                rc = ERR_NO_SHAPE;
            break;
        default:
            rc = ERR_UNKNOWN_CHOISE;
    }
    return rc;
}