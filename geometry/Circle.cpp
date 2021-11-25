//
// Created by dmitriy on 19.11.2021.
//

#include "Figures.h"
#include <cmath>

double Circle::area() {
    if(this->rr == 0)
        return this->r*this->r*M_PI;
    else{
        return this->r*this->rr*M_PI;
    }
}

Circle::Circle(double new_r, double new_rr) {
    if(new_rr == 0)
        this->name = "Circle";
    else{
        this->name = "Elipse";
    }
    this->r = new_r;
    this->rr = new_rr;
}
