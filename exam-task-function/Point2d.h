//
// Created by dmitriy on 20.01.2022.
//

#ifndef EXAM_TASK_FUNCTION_POINT2D_H
#define EXAM_TASK_FUNCTION_POINT2D_H

#include <ostream>
class Point2d {
private:
    double x;
    double y;
public:
    Point2d(double new_x, double new_y);
    double get_x();
    double get_y();
    friend std::ostream &operator<<(std::ostream &out, const Point2d &p){
        out << "X- " << p.x << std::endl;
        out << "Y- " << p.y << std::endl;
        return out;
    };
};


#endif //EXAM_TASK_FUNCTION_POINT2D_H
