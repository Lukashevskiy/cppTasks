//
// Created by dmitriy on 03.12.2021.
//

#ifndef SHAHKI_PREDICT_FIGURES_H
#define SHAHKI_PREDICT_FIGURES_H
#include <vector>
#include "istream"
class Figure {
protected:
    int type = -1;
public:
    virtual std::vector<std::pair<int,int>> possible_moves() = 0;
    virtual int who(){
        return -1;
    }
};


class King final : public Figure {
public:
    std::vector<std::pair<int, int>> possible_moves() override;
    int who() override{
       return 6;
    };
};


class Queen final : public Figure{
public:
    std::vector<std::pair<int, int>> possible_moves() override;
    int who() override{
        return 5;
    };
};


class Bishop final : public Figure{
public:
    std::vector<std::pair<int, int>> possible_moves() override;
    int who() override{
        return 4;
    };
};

class Knight final : public Figure{
public:
    std::vector<std::pair<int, int>> possible_moves() override;
    int who() override{
        return 3;
    };
};

class Rook final : public Figure{
public:
    std::vector<std::pair<int, int>> possible_moves() override;
    int who() override{
        return 2;
    };
};

class Pawn final : public Figure{
public:
    std::vector<std::pair<int, int>> possible_moves() override;
    int who() override{
        return 1;
    };
};
#endif //SHAHKI_PREDICT_FIGURES_H
