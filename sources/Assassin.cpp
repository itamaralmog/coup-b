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
            this->game_g->adacha.push_back(p.name);
            this->game_g->role_adacha.push_back(p.r);
            this->game_g->madiach.push_back(this->name);
            if(this->c <SEVEN){
                this->c-=3;
                this->move = Coup;
            }
            else{
                this->c-=SEVEN;
                this->move = Coup_7;
            }

            std::vector<string>::iterator it = std::find(this->game_g->names.begin(), this->game_g->names.end(), this->name);
            int index = std::distance(this->game_g->names.begin(), it);

            int ind = index+1;

            int si = (int) this->game_g->names.size();

            int t = ind % si;

            if(this->name != this->game_g->tt){
                throw "turn jump!";
            }
            this-> game_g->tt = this->game_g->names.at((unsigned long)t);
        }
        else{
            throw "not enough coins";
        }

    }
}