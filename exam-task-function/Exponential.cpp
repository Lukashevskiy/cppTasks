//
// Created by dmitriy on 20.01.2022.
//

#include "Exponential.h"

#include "Parabola.h"
#include <cmath>
// k * e^(x)
Exponential::Exponential(double new_k, int new_n): Function( "Exponential", new_k, new_n ){}

double Exponential::value(double x) {
    return k * pow(M_E, x);
}

Function *Exponential::integral(){
    //Function *e1 = new Exponential(k, 0, n), *b1 = new Parabola(n-1, 0, 1), *b2 = new Parabola(b, 0, 1);
    return nullptr;//new Hard_function(std::vector<Function*>{new Hard_function(std::vector<Function*>{e1,b1}, 1, 0, 1),b2}, 1, 0, 1);
}

Function *Exponential::differential() {
    return new Exponential(k, 1);
}

Point2d Exponential::max_of_func() {
    return Point2d(0, 0);
}

Point2d Exponential::min_of_func() {
    return Point2d(0, 0);
}
