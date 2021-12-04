//
// Created by dmitriy on 04.12.2021.
//

#include "../headers/Cell.h"

Cell::Cell(Figure *new_figure, int new_x, int new_y) {
    this->figure = new_figure;
    this->x = new_x;
    this->y = new_y;
}

void Cell::change_figure(Figure &figures) {
    this->figure = &figures;
}

Figure* Cell::get_figure() {
    return this->figure;
}

Cell::Cell(const Cell &cell){
    this->figure = cell.figure;
}

std::ostream &operator<<(std::ostream &out, Cell &c) {
    out << "[" << c.figure->who() << "]";
    return out;
}
