#include "../inc/my_geometry.hpp"

int get_distanse_between_points(double &distanse, const my_point &p1, const my_point &p2) // может уехать к my_point
{
    distanse = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    return OK;
}
int get_line(my_3d_line &res, const my_vector &direct)
{
    res.direct = direct;
    return OK;
}
int get_line(my_3d_line &res, const my_point &p1, const my_point &p2)
{
    my_vector direct;
    direct.start = p1;
    direct.end = p2;
    
    res.direct = direct;
    return OK;
}
/*
int get_line(my_3d_line &res, const my_vector &normal_direct, const my_point &base_point)
{
    my_vector_coordinates normal_coordinates, direct_coordinates;
    get_vector_coordinates(normal_coordinates, normal_direct);
    res.direct = direct;
    return OK;
}*/

int get_intersection_by_two_lines(my_point &intersection, const my_3d_line &l1, const my_3d_line &l2);
int get_surface(my_surface &res, const my_vector &normal, const my_point &base_point);
int get_intersection_by_line_and_surface(my_point &intersection, const my_surface &surface, const my_3d_line &line);
int get_distanse_between_points(double &distanse, const my_point &p1, const my_point &p2); // может уехать к my_point
int get_2d_coordinates(my_2d_point &res, const my_point &object, my_camera &camera);