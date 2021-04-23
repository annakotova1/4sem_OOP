#ifndef DOWNLOADPOINTS_H
#define DOWNLOADPOINTS_H

#include "errors.hpp"
#include "my_points_list.hpp"

int downloadPoints(all_points &object, char *filename);

// Считать точку из файла
int read_point(shape_point &p, FILE *file);
// Считать точки из файла
// Считать ребро
int read_line(list_points_node *head, FILE *file);
// Проверить считаное
int check_point(const shape_point &point, list_points_node *head);
// Скопировать список в результат
//


#endif