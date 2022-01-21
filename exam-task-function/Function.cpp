//
// Created by dmitriy on 20.01.2022.
//

#include "Function.h"

#include <utility>

Function::Function(std::string new_type, double new_k, int new_n) :type{ std::move(new_type) }, k{ new_k }, n{ new_n } {}

void Function::set_k(double new_k) {
    this->k = new_k;
}


double pow(double number, int n){
    double ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= number;
    }
    return ans;
}