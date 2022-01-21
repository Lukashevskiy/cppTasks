//
// Created by dmitriy on 21.01.2022.
//

#include "Line.h"

Line::Line(double new_k): Parabola(new_k, 1){
    this->type = "Line";
}

std::string Line::get_expression() {
    std::string ans = "";
    if(k>1){
        ans+= std::to_string(k)+"*";
    }
    ans += 'x';
    return ans;
}
