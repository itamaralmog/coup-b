#pragma once
#include "Player.hpp"

namespace coup{
    class Ambassador : public Player{
        public:
        Ambassador(Game &g, const std::string &n):Player(g,n /*" Ambassador"*/){
            this->r="Ambassador";
        }
        void transfer(Player &p1, Player &p2);
        static void block(Player &p);
    };
}