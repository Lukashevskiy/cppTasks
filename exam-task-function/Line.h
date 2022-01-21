//
// Created by dmitriy on 21.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_LINE_H
#define EXAM_TASK_FUNCTION_LINE_H
#include "Parabola.h"

class Line : public Parabola{
public:
    explicit Line(double new_k);
    std::string get_expression() override;
};


#endif //EXAM_TASK_FUNCTION_LINE_H
