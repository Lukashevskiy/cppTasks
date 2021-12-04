//
// Created by dmitriy on 03.12.2021.
//

#include "../headers/Field.h"
Field::Field() {
    this->n = 8;
    this->m = 8;
    this->field.reserve(8);
    for(int i = 0; i < this->field.size(); i++){
        this->field[i].reserve(8);
        for(int j = 0; j < this->field[i].size(); j++){
            field[i][j] = new Cell(new Bishop(), i, j);
        }
    }
}

Field::Field(std::vector<std::vector<Cell*>> &new_field) {
    this->n = 8;
    this->m = 8;
    this->field = new_field;
}

std::ostream &operator<<(std::ostream &out, Field &f) {
    for(int j = 0; j < 8; j++) {
        out << " - - - - - - - - \n";
        for (int i = 0; i < 8; i++) {
            out << "|" << &f.field[j][i];
        }
        out << std::endl;
    }
    return out;
}



void Field::add_field(std::vector<std::vector<Cell*>> &new_field) {
    this->field = new_field;
}

void Field::change_cell(int i, int j, Cell &cell) {
    if( 0 > i || i > 8 || j < 0 || j > 8){
        throw std::exception();
    }
    this->field[i][j] = &cell;
}


