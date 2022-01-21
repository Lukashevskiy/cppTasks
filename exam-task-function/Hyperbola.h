//
// Created by dmitriy on 20.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_HYPERBOLA_H
#define EXAM_TASK_FUNCTION_HYPERBOLA_H

#include <string>
#include "Function.h"

class Hyperbola : public Function{

public:
    Hyperbola(double new_k, int new_n);

    virtual double value(double x) override;
    virtual Function * integral() override;
    virtual Function * differential() override;

    virtual Point2d max_of_func(double start, double stop) override;
    virtual Point2d min_of_func(double start, double stop) override;
};


#endif //EXAM_TASK_FUNCTION_HYPERBOLA_H
