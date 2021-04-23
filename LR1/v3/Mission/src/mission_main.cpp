#include "../inc/my_domens_interaction.hpp"
#include "../inc/my_points_list.hpp"

int mission_main(domens_interaction &data)
{
	int rc = OK;
	static all_points object = init();
	switch (data.command)
	{
		case DOWNLOAD: // нужна фигура и название файла
			rc = download_points(object, data.filename);
			break;
		case TRANSFORM: // нужна фигура и настройки (камера не нужна)
			rc = transform_shape(object, data.settings);
			break;
		case DRAW: // нужна фигура и камера и группа (куда рисовать)
			rc = draw_picture(object, data.group);
			break;
		case EXIT:
			break;
		default:
			rc = ERR_UNKNOWEN_COMMAND;
	}
	return rc;
}