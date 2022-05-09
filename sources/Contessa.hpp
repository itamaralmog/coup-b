#pragma once
#include "Player.hpp"

namespace coup{
    class Contessa : public Player{
    public:
        Contessa(Game &g,const std::string &n):Player(g,n /*" Contessa"*/){
            this->r="Contessa";

        }
        void block(Player &p);
    };
    
    
}