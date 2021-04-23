#include "../shape/shape.hpp"
#include "../settings/settings.hpp"

int task_main(task_settings_t settings)
{
    int rc;
    static shape_t shape = init_shape();
    switch(settings.command)
    {
        case DOWNLOAD:
            rc = download_shape(shape, get_download_settings(settings));
            break;
        case TRANSFORM:
            rc = transform_shape(shape, get_transform_settings(settings));
            break;
        case DRAW:
            rc = draw_shape(shape, settings.command_settings);
            break;
        case EXIT:
            rc = exit(shape);
            break;
        default:
            rc = ERR_UNKNOWN_CHOISE;
    }
    return rc;
}