//
// Created by dmitriy on 04.12.2021.
//

#include "../headers/Player.h"
#include "../headers/Cell.h"

Player::Player(){
    figures.reserve(16 * sizeof( Cell));
    figures[0] = new Rook;
    figures[1] = new Knight;
    figures[2] = new Bishop;
    figures[3] = new King;
    figures[4] = new Queen;
    figures[5] = new Bishop;
    figures[6] = new Knight;
    figures[7] = new Rook;
    for(int i = 8; i < 16; i++){
        figures[i] = new Pawn;
    }
};

Player::Player(const std::vector<Figure *> &new_figures) {
    this->figures = new_figures;
}

void Player::move() {

}

Player::~Player() {
    delete[] &figures;
}
