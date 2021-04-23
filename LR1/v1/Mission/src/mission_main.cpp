#include "../inc/my_domens_interaction.hpp"
#include "../inc/my_points_list.hpp"

int mission_main(domens_interaction &data)
{
	int rc = OK;
	switch (data.command)
	{
		case DOWNLOAD: // нужна фигура и название файла
			rc = download_points(data.object, data.filename);
			break;
		case TRANSFORM: // нужна фигура и настройки (камера не нужна)
			rc = transform_shape(data.object, data.settings);
			break;
		case DRAW: // нужна фигура и камера и группа (куда рисовать)
			rc = draw_picture(data.object, data.camera, data.group);
			break;
		default:
			rc = ERR_UNKNOWEN_COMMAND;
	}
	return rc;
}
/*
int main()
{
	return OK;
}*/