//
// Created by dmitriy on 20.01.2022.
//
// k/x
#include "Hyperbola.h"

#include "Parabola.h"
#include "Log.h"

Hyperbola::Hyperbola(double new_k): Function( "Hyperbola", new_k, 1){}

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
    return new Log(k);//new Hyperbola();
}

Point2d Hyperbola::max_of_func(double start, double stop) {
    //Function *d = this->differential();
    double start_v, stop_v;
    bool is_start = false, is_stop = false;
    try{
        start_v = this->value(start);
    } catch( std::invalid_argument){
        is_start = true;
    };

    try{
        stop_v = this->value(stop);
    } catch( std::invalid_argument){
        is_stop = true;
    };

    if(is_start && is_stop){
        if(start_v > stop_v){
            return Point2d(start, start_v);
        }else{
            return Point2d(stop, stop_v);
        }
    }else if(is_start){
        return Point2d(start, start_v);
    }else if(is_stop){
        return Point2d(stop, stop_v);
    }else{
        throw std::empty("no one");
    }
}

Point2d Hyperbola::min_of_func(double start, double stop) {
    double start_v, stop_v;
    bool is_start = false, is_stop = false;
    try{
        start_v = this->value(start);
    } catch( std::invalid_argument){
        is_start = true;
    };

    try{
        stop_v = this->value(stop);
    } catch( std::invalid_argument){
        is_stop = true;
    };

    if(is_start && is_stop){
        if(start_v < stop_v){
            return Point2d(start, start_v);
        }else{
            return Point2d(stop, stop_v);
        }
    }else if(is_start){
        return Point2d(start, start_v);
    }else if(is_stop){
        return Point2d(stop, stop_v);
    }else{
        throw std::empty("no one");
    }

}

std::string Hyperbola::get_expression() {
    return std::to_string(k)+"/x";
}

