//
// Created by dmitriy on 21.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_POLINOM_H
#define EXAM_TASK_FUNCTION_POLINOM_H

#include <vector>
#include "Function.h"
class Polinom : public Function{
private:
    std::string pol_type;
    std::vector<Function*> functions;
    Function * integral() override;
    Function * differential() override;
    double value(double x) override;

    Point2d min_of_func(double start, double stop) override;
    Point2d max_of_func(double start, double stop) override;

public:
    explicit Polinom(std::vector<Function*> new_functions, std::string new_pol_type);
    std::string get_expression() override;
};


#endif //EXAM_TASK_FUNCTION_POLINOM_H
