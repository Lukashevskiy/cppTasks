//
// Created by dmitriy on 21.01.2022.
//

#include "Hard_function.h"
#include "Polinom.h"

Hard_function::Hard_function(Function *new_out, Function *new_in) : Function("Hard Func", new_out->get_k(), new_out->get_k()){
    in = new_in;
    out = new_out;
    out->set_k(1);
}

double Hard_function::value(double x) {
    return k * out->value(in->value(x));
}

std::string Hard_function::get_expression() {
    std::string ans = "";
    std::string ans_in = in->get_expression();
    std::string ans_out = out->get_expression();
    for(char i : ans_out){
        if(i == 'x'){
            ans += '(';
            ans += ans_in;
            ans += ')';
        }else{
            ans += i;
        }
    }
    return ans;
}

Point2d Hard_function::min_of_func(double start, double stop) {
    return Point2d(0, 0);
}

Point2d Hard_function::max_of_func(double start, double stop) {
    return Point2d(0, 0);
}

Function *Hard_function::integral() {
    return nullptr;
}

Function *Hard_function::differential() {
    Function *diff_in = in->differential();
    Function *diff_out = out->differential();
    Function *hard = new Hard_function(diff_out, diff_in);
    return  new Polinom(std::vector<Function*>{hard, diff_in}, "Hard");
}
