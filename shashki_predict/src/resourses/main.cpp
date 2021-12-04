#include <iostream>
#include <istream>
#include "../headers/Field.h"
#include "../headers/Player.h"
using namespace std;
struct Game{
    Field *field;
    Player *white, *black;
    Game(Field &new_field, Player &p1, Player &p2){
        this->field = &new_field;
        this->black = &p1;
        this->white = &p2;
    };

    Game(){
        this->field = new Field;
        this->white = new Player;
        this->black = new Player;
    };



};
int main(){
    Field new_field;
    cout << new_field;
    return 0;
}
