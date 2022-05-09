#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <exception>
using namespace std;
const unsigned long SIX = 6;
const unsigned long SEVEN = 7;
const unsigned long TEN = 10;
namespace coup
{
    class Player;
    class Game;
    enum moves {No_move,Income,Foreign_aid,Coup,Tax,Transfer,Steal,Block,Coup_7};
    class Game
    {
        public:
        std::vector<Player> player_s;
        std::vector<std::string> names;
        std::vector<std::string> roles;
        std::vector<std::string> adacha;
        std::vector<std::string> role_adacha;
        std::vector<std::string> madiach;
        std::string tt;
        bool turn_init;
        bool started;
        int play=0;
        public:
        Game(){ 
            std::vector<Player> p;
            std::vector<std::string> n;
            std::vector<std::string> r;
            std::vector<std::string> ad;
            std::vector<std::string> ro;
            std::vector<std::string> mad;
            std::string t;
            this->player_s = p;
            this->names=n;
            this->roles=r;
            this->tt=t;   
            this->adacha = ad; 
            this->role_adacha = ro;
            this->madiach = mad;
            bool turn_init = false;
            bool started = false;
            int play = 0;
        }
        std::vector<std::string> players(){
            return this->names;
        }
        std::string turn() const;
        std::string winner(){
            
            if(this->started){
                throw "game in progress";
            }
            if(this->names.size() == 1){
                return this->names.at(0);
            }
            else{
                throw "game in progress";
            }
        }
    };
    class Player
    {
        public:
        Player *arch;
        bool dead;
        int place;
        std::string name;
        Game *game_g;
        int c;
        std::string r;
        int move;
        public:
        Player(Game &game, std::string const & name);
        void income();
        void foreign_aid();
        virtual void coup(Player &p);
        virtual std::string role();
        virtual int coins();
    };
}