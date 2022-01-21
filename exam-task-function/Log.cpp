//
// Created by dmitriy on 21.01.2022.
//

#include "Log.h"
#include <cmath>

Log::Log(double new_k) : Function("EXP Logarithm", new_k, 1){ }

double Log::value(double x) {
    return k*log(x);
}

std::string Log::get_expression() {
    std::string ans = "";
    if(k>1) {
        ans += std::to_string(k)+"*";
    }
    ans+="ln(x)";
    return ans;
    return std::to_string(k)+"*ln(x)";
}

Function *Log::integral() {
    return nullptr;
}

Function *Log::differential() {
    return nullptr;
}

Point2d Log::max_of_func(double start, double stop) {
    return Point2d(0, 0);
}

Point2d Log::min_of_func(double start, double stop) {
    return Point2d(0, 0);
}
