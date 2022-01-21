//
// Created by dmitriy on 20.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_FUNCTION_H
#define EXAM_TASK_FUNCTION_FUNCTION_H

#include <utility>
#include <string>
#include "Point2d.h"
#include <ostream>

class Function {
protected:
    double k;
    int n;
    std::string type;
public:
    virtual double value(double x) = 0;
    virtual Point2d max_of_func() = 0;
    virtual Point2d min_of_func() = 0;
    virtual Function* integral() = 0;
    virtual Function* differential() = 0;
    [[nodiscard]] std::string get_type() const{
        return this->type;
    };
    explicit Function(std::string new_type, double new_k, int new_n);

    //Function();
};

double pow(double number, int n);

#endif //EXAM_TASK_FUNCTION_FUNCTION_H
