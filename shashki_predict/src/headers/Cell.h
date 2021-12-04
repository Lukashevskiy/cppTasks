//
// Created by dmitriy on 04.12.2021.
//

#ifndef SHAHKI_PREDICT_CELL_H
#define SHAHKI_PREDICT_CELL_H
#include "Figures.h"
#include <istream>
class Cell {
private:
    Figure *figure;
    int x;
    int y;
public:
    Cell(Figure *figure, int x, int y);
    Cell(const Cell &cell);
    void change_figure(Figure &figures);
    Figure *get_figure();
    friend std::ostream &operator<<(std::ostream &out, Cell &c);
};


#endif //SHAHKI_PREDICT_CELL_H
