//
// Created by dmitriy on 20.01.2022.
//

#include "Parabola.h"
#include "Line.h"
// k * x^2
Parabola::Parabola(double new_k, int new_n): Function( "Parabola", new_k, new_n){}
Parabola::Parabola(double new_k): Function("Exponential", new_k, 1){}

double Parabola::value(double x) {
    return k * pow(x, n);
}

Function *Parabola::integral() {
    return new Parabola(k/n+1, n+1);
}

Function *Parabola::differential() {
    return new Line(2*k);
}

Point2d Parabola::max_of_func(double start, double stop) {
    Function *d = this->differential();
    double start_v, stop_v, diff_v;
    start_v = this->value(start);
    stop_v = this->value(stop_v);
    diff_v = d->value(0);
    if(start_v > stop_v){
        if(diff_v > start_v){
            return Point2d(0, diff_v);
        }else{
            return Point2d(start, start_v);
        }
    }else{
        if(diff_v > stop_v){
            return Point2d(0, diff_v);
        }else{
            return Point2d(stop, stop_v);
        }
    }
    //return Point2d(0, 0);
}

Point2d Parabola::min_of_func(double start, double stop) {
    Function *d = this->differential();
    double start_v, stop_v, diff_v;
    start_v = this->value(start);
    stop_v = this->value(stop_v);
    diff_v = d->value(0);
    if(start_v > stop_v){
        if(diff_v < start_v){
            return Point2d(0, diff_v);
        }else{
            return Point2d(start, start_v);
        }
    }else{
        if(diff_v < stop_v){
            return Point2d(0, diff_v);
        }else{
            return Point2d(stop, stop_v);
        }
    }
    //return Point2d(0, 0);
}

std::string Parabola::get_expression() {
    std::string ans = "";
    if(k>1){
        ans+= std::to_string(k)+"*";
    }
    ans += "1/(x^2)";
    return ans;
}


