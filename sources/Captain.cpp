#include "Captain.hpp"

namespace coup{
    void Captain::steal(Player &p){
        // Player p1 = *this;
        this->calc_turn();
        if(p.c < 2){
            p.c-=1;
            p.place=1;
            this->c+=1; 
        }
        else{
            p.c-=2;
            p.place =2;
            this->c+=2;
        }
        this->arch = &p;      
        this->move = Steal;
    }

    void Captain::block(Player &p){
        if(p.r != "Captain"){
            throw "not a captain!";
        }
        p.arch->c +=  p.arch->place;
        p.c -= p.arch->place;
    }
}