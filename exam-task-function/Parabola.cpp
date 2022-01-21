//
// Created by dmitriy on 20.01.2022.
//

#include "Parabola.h"

// k * x^n
Parabola::Parabola(double new_k, int new_n): Function( "Parabola", new_k, new_n){}

double Parabola::value(double x) {
    return k * pow(x, n);
}

Function *Parabola::integral() {
    return new Parabola(k/n+1, n+1);
}

Function *Parabola::differential() {
    return new Parabola(k+n, n-1);
}

Point2d Parabola::max_of_func(double start, double stop) {
    Function *d = this->differential();
    return Point2d(0, 0);
}

Point2d Parabola::min_of_func(double start, double stop) {
    return Point2d(0, 0);
}
