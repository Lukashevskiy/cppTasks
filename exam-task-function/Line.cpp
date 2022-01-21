//
// Created by dmitriy on 21.01.2022.
//

#include "Line.h"

Line::Line(double new_k): Parabola(new_k, 1){
    this->type = "Line";
}

std::string Line::get_expression() {
    return std::to_string(k)+"x";
}
