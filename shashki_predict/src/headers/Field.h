//
// Created by dmitriy on 03.12.2021.
//

#ifndef SHAHKI_PREDICT_FIELD_H
#define SHAHKI_PREDICT_FIELD_H
#include <vector>
#include <istream>
#include "Cell.h"
class Field {
private:
    int n = 8;
    int m = 8;
    std::vector<std::vector<Cell*>> field;
public:
    Field();
    Field(std::vector<std::vector<Cell*>> &new_field);
    void add_field(std::vector<std::vector<Cell*>> &new_field);
    void change_cell(int i, int j, Cell &cell);
    friend std::ostream &operator<<(std::ostream &out, Field &f);

};


#endif //SHAHKI_PREDICT_FIELD_H
