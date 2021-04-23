#include "../inc/my_domens_interaction.hpp"

int mission_main(domens_interaction &data)
{
	int rc;
	switch (data.command)
	{
		case DOWNLOAD: // нужна фигура и название файла
			rc = downloadPoints(data.object, data.filename);
			break;
		case TRANSFORM: // нужна фигура и настройки (камера не нужна)
			rc = transformFigure(data.object, data.settings);
			break;
		case DRAW: // нужна фигура и камера и группа (куда рисовать)
			rc = drawPicture(data.object, data.camera, data.group);
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