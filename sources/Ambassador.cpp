#include "Ambassador.hpp"

using namespace std;

namespace coup{
    void Ambassador::transfer(Player &p1, Player &p2){
        if(p1.c == 0){
            throw "cant move zero";
        }
        --p1.c;
        ++p2.c;
        this->calc_turn();
        this->move = Transfer;
    }
    void Ambassador::block(Player &p){
        if(p.r != "Captain"){
            throw "not a captain!";
        }
        p.arch->c +=  p.arch->place;
        p.c -= p.arch->place; 
    }
}