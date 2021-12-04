//
// Created by dmitriy on 04.12.2021.
//

#ifndef SHAHKI_PREDICT_PLAYER_H
#define SHAHKI_PREDICT_PLAYER_H
#include "Figures.h"
#include <vector>

class Player {
private:
    std::vector<Figure *> figures;
public:
    Player();
    explicit Player(const std::vector<Figure *> &new_figures);
    void move();
    ~Player();
};


#endif //SHAHKI_PREDICT_PLAYER_H
