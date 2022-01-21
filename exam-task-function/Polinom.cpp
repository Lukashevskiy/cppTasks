//
// Created by dmitriy on 21.01.2022.
//

#include "Polinom.h"

#include <utility>

Polinom::Polinom(std::vector<Function *> new_functions, std::string new_pol_type) : Function("Polinom", 1, 1){
    this->functions = std::move(new_functions);
    this->pol_type = new_pol_type;
    if(pol_type == "Hard"){
        for(Function * fun : functions){
            k*=fun->get_k();
            fun->set_k(1);
        }
    }
}

Function *Polinom::integral() {
    return nullptr;
}

Function *Polinom::differential() {
    return nullptr;
}

double Polinom::value(double x) {
    return 0;
}

Point2d Polinom::max_of_func(double start, double stop) {
    return Point2d(0, 0);
}

std::string Polinom::get_expression() {
    std::string ans = "";
    if(k > 1 || k < 0){
        ans += std::to_string(k)+"*";
    }
    for(int i = 0; i < functions.size(); i++){
        ans += functions[i]->get_expression();
        if(i < functions.size()-1){
            if(pol_type == "Hard"){
                ans += '*';
            }else{
                ans += '+';
            }
        }
    }
    return ans;
}

Point2d Polinom::min_of_func(double start, double stop) {
    return Point2d(0, 0);
}
