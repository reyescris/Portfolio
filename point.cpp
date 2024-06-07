#include "shapes.h"
#include <iostream>
#include <cmath>

void Point::Input(void)
{
    std::cout << "Enter coordinate like this (x,y): \n";
    char trash;
    std::cin >> trash >> x >> trash >> y >> trash;
    return;
}

void Point::Output(void)
{
    std::cout << "(" << x << "," << y << ")";
    return;
}

double Point::distance(const Point & other) const
{
    return sqrt(pow(other.x-x, 2.0) +
    pow(other.y-y, 2.0));
}

Point Point::midpoint(const Point & other) const
{
    double mid_x = x;
    double mid_y = (y + other.y) / 2.0;
    return Point(mid_x, mid_y);
}

void Point::set_x(double new_x)
{
    x = new_x;
    return;
}

void Point::set_y(double new_y)
{
    y = new_y;
    return;
}

Point::Point(void)
{
    x = y = 0.0;
}

Point::Point(double new_x, double new_y)
{
    set_x(new_x);
    set_y(new_y);
}

