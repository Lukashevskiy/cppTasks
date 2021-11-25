//
// Created by dmitriy on 19.11.2021.
//

#ifndef UNTITLED3_FIGURES_H
#define UNTITLED3_FIGURES_H
#include <vector>
#include <string>
#include <istream>

class Figure{
protected:
    std::string name = "Unnamed";
public:
    virtual double area() = 0;
    friend std::ostream &operator<<(std::ostream &out, Figure &figure) {
        out << figure.name << " " << figure.area() << std::endl;
        return out;
    }
};

class Circle : public Figure{
protected:
    double r;
    double rr;
public:
    explicit Circle(double new_r, double new_rr=0);

    double area();
};


class Square : public Figure{
protected:
    double x;
    double y;
public:
    explicit Square(double new_x, double new_y=0);
    double area();
};


class Triangle: public Figure{
private:
    double a,b,c;
public:
    Triangle(double new_a, double new_b, double new_c);
    double area();
};

class Point2d{
private:
    double x;
    double y;
public:
    Point2d();
    Point2d(double new_x, double new_y);
    Point2d &operator=(Point2d point);
    double &get_x();
    double &get_y();
};
class Polygon: public Figure{
private:
    std::vector<Point2d> points;
public:
    explicit Polygon(std::vector<Point2d> &points);
    Point2d operator[](unsigned long index) const;
    double area();
};
#endif //UNTITLED3_FIGURES_H
