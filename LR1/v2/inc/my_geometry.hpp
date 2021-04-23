#ifndef MYGEOMETRY_H
#define MYGEOMETRY_H

#include <cmath>

#include "my_point.hpp"
#include "my_vector.hpp"
#include "my_camera.hpp"
#include "my_points_list.hpp"

struct my_2d_point
{
    double x;
    double y;
};

struct my_3d_line
{
    my_vector direct;
};

struct my_surface
{
    double a;
    double b;
    double c;
    double d;
};

int get_line(my_3d_line &res, const my_vector &direct);
int get_line(my_3d_line &res, const my_point &p1, const my_point &p2);
int get_line(my_3d_line &res, const my_vector &normal_direct, const my_point &base_point);
int get_intersection_by_two_lines(my_point &intersection, const my_3d_line &l1, const my_3d_line &l2);

int get_surface(my_surface &res, const my_vector &normal, const my_point &base_point);
int get_intersection_by_line_and_surface(my_point &intersection, const my_surface &surface, const my_3d_line &line);

int get_distanse_between_points(double &distanse, const my_point &p1, const my_point &p2); // может уехать к my_point

int get_2d_coordinates(my_2d_point &res, const my_point &object, my_camera &camera);

#endif
