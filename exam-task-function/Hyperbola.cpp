//
// Created by dmitriy on 20.01.2022.
//
// k/x
#include "Hyperbola.h"

#include "Parabola.h"

Hyperbola::Hyperbola(double new_k, int new_n): Function( "Hyperbola", new_k, new_n){}

double Hyperbola::value(double x) {
    if(x == 0){
        throw std::invalid_argument("0");
    }else{
        return (k / pow(x, n));
    }
}

Function *Hyperbola::integral() {
    return nullptr;
}

Function *Hyperbola::differential() {
    return nullptr//new Hyperbola();
}

Point2d Hyperbola::max_of_func() {
    //Function *d = this->differential();

    return Point2d(0,0);
}

Point2d Hyperbola::min_of_func() {
    return Point2d(0,0);
}

