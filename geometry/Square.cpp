//
// Created by dmitriy on 19.11.2021.
//

#include "Figures.h"

Square::Square(double new_x, double new_y) {
    if(new_y == 0)
        this->name = "Square";
    else{
        this->name = "Rectangle";
    }
    this->y = new_y;
    this->x = new_x;
}

double Square::area() {
    if(this->y == 0){
        return x*x;
    }else{
        return x*y;
    }
}
