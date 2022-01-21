//
// Created by dmitriy on 20.01.2022.
//

#include "Point2d.h"

Point2d::Point2d(double new_x, double new_y): x{ new_x }, y{ new_y } { }

double Point2d::get_x() {
    return this->x;
}

double Point2d::get_y() {
    return this->y;
}
