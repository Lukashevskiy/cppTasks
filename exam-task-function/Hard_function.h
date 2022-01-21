//
// Created by dmitriy on 21.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_HARD_FUNCTION_H
#define EXAM_TASK_FUNCTION_HARD_FUNCTION_H
#include "Function.h"
// k * f(g(x))
class Hard_function : public Function{
private:
    Function *out;
    Function *in;
    Point2d min_of_func(double start, double stop) override;
    Point2d max_of_func(double start, double stop) override;

    Function * integral() override;
public:
    Hard_function(Function *new_out, Function *new_in);
    double value(double x) override;
    Function * differential() override;
    std::string get_expression() override;

};


#endif //EXAM_TASK_FUNCTION_HARD_FUNCTION_H
