//
// Created by dmitriy on 21.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_LOG_H
#define EXAM_TASK_FUNCTION_LOG_H
#include "Function.h"

class Log: public Function{
public:
    double value(double x) override;

    Function * integral() override;
    Function * differential() override;

    Point2d max_of_func(double start, double stop) override;
    Point2d min_of_func(double start, double stop) override;
    Log(double new_k);
};


#endif //EXAM_TASK_FUNCTION_LOG_H
