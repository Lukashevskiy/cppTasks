#include <iostream>
#include "Figures.h"
#include <vector>
using namespace std;

/*

class Base{
public:
    virtual void who(){
        cout << "BASE" << endl;
    };
};

class First : public  Base{
public:
    void who() {
        cout << "First" << endl;
    };
};

class Second : public Base{
public:
    void who(){
        cout << "Second" << endl;
    }
};

void is_who(Base &ptr){
    ptr.who();
}
*/

int main() {
    /*Base b;
    First f;
    Second s;
    is_who(f);
    is_who(s);
    is_who(b);*/
    vector<Figure*> figures;
    Triangle *triangle = new Triangle(1,1,1);
    Circle *circle = new Circle(10);
    Circle *ellipse = new Circle(10,10);
    Square *square = new Square(10);
    Square *rectangle = new Square(20,10);

    Point2d p1(1,2);
    Point2d p2(2,1);
    Point2d p3(10,2);
    vector<Point2d> coords = {p1, p2, p3};
    Polygon *polygon = new Polygon(coords);

    figures.push_back(triangle);
    figures.push_back(circle);
    figures.push_back(ellipse);
    figures.push_back(square);
    figures.push_back(rectangle);
    figures.push_back(polygon);
    for(Figure *figure: figures){
        cout << *figure;
    }
    return 0;
}
