#include "Contessa.hpp"

namespace coup{
    void Contessa::block(Player &p){
       if(p.r!="Assassin"){
           throw "not assassin";
       }
       if(p.move != Coup){
           throw "not coup by spacial in assaian";
       }
       if(p.move == Coup_7){
           throw "unstopable coup";
       }
        auto itPos = this->game_g->names.begin() + p.place;
        this->game_g->names.insert(itPos,p.arch->name);
        p.arch->dead=false;
        p.arch =&p;
    }

}