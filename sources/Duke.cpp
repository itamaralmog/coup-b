#include "Duke.hpp"

namespace coup{
    void Duke::tax(){
        Player p = *this;
        p.calc_turn();
        this->move = Tax;
        this->c+=3;
    }
    void Duke::block(Player &p){
        if(p.move== Foreign_aid){
            p.c-=2;
        }
        else{
            throw "not that move";
        }
    }
}