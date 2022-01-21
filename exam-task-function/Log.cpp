//
// Created by dmitriy on 21.01.2022.
//

#include "Log.h"
#include <cmath>

Log::Log(double new_k) : Function("EXP Logarithm", new_k, 1){ }

double Log::value(double x) {
    return log(x);
}
