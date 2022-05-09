#pragma once
#include "Player.hpp"

namespace coup{
    class Assassin : public Player
    {
        public:
        Assassin(/* args */ Game &g,const std::string &n):Player(g,n /*" Assassin"*/){
            this->r="Assassin";
        }
        void coup(Player &p) override;
    };
    
}