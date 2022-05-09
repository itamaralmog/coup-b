#pragma once
#include "Player.hpp"

namespace coup{
    class Captain : public Player
    {
    public:
        Captain(/* args */Game &g,const std::string &n):Player(g,n /*" Captain"*/){
            this->r="Captain";
        }
        void steal(Player &p);
        static void block(Player &p);
    };
    
}