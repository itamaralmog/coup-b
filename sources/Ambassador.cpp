#include "Ambassador.hpp"

using namespace std;

namespace coup{
    void Ambassador::transfer(Player &p1, Player &p2){
        if(p1.c == 0){
            throw "cant move zero";
        }
        --p1.c;
        ++p2.c;
        Player p = *this;

        std::vector<string>::iterator it = std::find(p.game_g->names.begin(), p.game_g->names.end(), p.name);
        int index = std::distance(p.game_g->names.begin(), it);

        int ind = index+1;

        int si = (int) p.game_g->names.size();

        int t = ind % si;

        if(p.name != p.game_g->tt){
            throw "turn jump!";
        }
        this-> game_g->tt = p.game_g->names.at((unsigned long)t);
        this->move = Transfer;
    }
    void Ambassador::block(Player &p){
        p.arch->c +=  p.arch->place;
        p.c -= p.arch->place; 
    }
}