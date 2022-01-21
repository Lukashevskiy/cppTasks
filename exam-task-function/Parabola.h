//
// Created by dmitriy on 20.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_PARABOLA_H
#define EXAM_TASK_FUNCTION_PARABOLA_H
#include "Function.h"

class Parabola : public Function{
public:
    Parabola(double new_k, int new_n);

    virtual double value(double x) override;
    virtual Function * integral() override;
    virtual Function * differential() override;

    virtual Point2d max_of_func() override;
    virtual Point2d min_of_func() override;
};


#endif //EXAM_TASK_FUNCTION_PARABOLA_H
