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
        std::string tt;
        bool started;
        public:
        Game(){};
        std::vector<std::string> players() const;
        std::string turn() const;
        std::string winner();
    };

    class Player
    {
        public:
        int place;
        int c;
        int move;
        bool dead;
        std::string name;
        std::string r;
        Player *arch;
        Game *game_g;
        public:
        Player(Game &game, std::string const & name);
        void income();
        void foreign_aid();
        void income_aid(int m);
        void calc_turn() const;
        virtual void coup(Player &p);
        virtual std::string role();
        virtual int coins();
    };
}