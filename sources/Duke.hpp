#pragma once
#include "Player.hpp"

namespace coup{
    class Duke : public Player{

    public:
        Duke(Game &g,const std::string &n) : Player(g,n /*" Duke"*/){
            this->r="Duke";
        }
        void tax();
        static void block(Player &p);
    };

}