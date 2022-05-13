#include "Assassin.hpp"

namespace coup{
    void Assassin::coup(Player &p){
        if(p.dead){
            throw "already dead";
        }
        if(this->c >= 3){
            this->arch = &p;
            p.dead =true;
            std::vector<string>::iterator it1 = std::find(p.game_g->names.begin(), p.game_g->names.end(), p.name);
            int index1 = std::distance(p.game_g->names.begin(), it1);
            this->game_g->names.erase(it1);
            this->place = index1;
            if(this->c <SEVEN){
                this->c-=3;
                this->move = Coup;
            }
            else{
                this->c-=SEVEN;
                this->move = Coup_7;
            }
            this->calc_turn();
        }
        else{
            throw "not enough coins";
        }

    }
}