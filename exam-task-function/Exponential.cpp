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
    return new Exponential(k, 1);
}

Function *Exponential::differential() {
    return new Exponential(k, 1);
}

Point2d Exponential::max_of_func(double start, double stop) {
    return Point2d(0, 0);
}

Point2d Exponential::min_of_func(double start, double stop) {
    return Point2d(0, 0);
}
