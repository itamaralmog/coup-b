#include "Player.hpp"
using namespace std;
namespace coup
{
    Player::Player(Game &game, string const &name){
        if(game.names.size()+1 > SIX){
            throw std::out_of_range{"Fail"};
        }
        this->dead = false;
        this->arch = this;
        this->place=-1;
        const char ch = ' ';
        unsigned long space = 0;
        this->name = name;
        game.names.push_back(this->name); 
        this->move = No_move;
        this->c=0;
        game.started = true;
        if(!game.turn_init){
                game.tt = this->name;
                game.turn_init = true;
        }
        game.player_s.push_back(*this);
        for(unsigned long i = 0 ; i < game.player_s.size(); i++){
            if(game.player_s.at(i).move != No_move){
                throw "game started";
            }
            game.tt = game.names.at(0);
            game.player_s.at(i).game_g = &game;
        }
        this->game_g = &game;
    }
    void Player::income(){
        Player p = *this;
        if(p.game_g->names.size() <2){
            throw "to lower players";
        }
        if(p.c > TEN){
            throw "to many coins";
        }
        p.game_g->started = false;
        std::vector<string>::iterator it = std::find(p.game_g->names.begin(), p.game_g->names.end(), p.name);
        int index = std::distance(p.game_g->names.begin(), it);
        int ind = index+1;
        int si = (int) p.game_g->names.size();
        int t = ind % si;
        if(p.name != p.game_g->tt){
            throw "turn jump!";
        }
        for(unsigned long i = 0 ; i < this->game_g->player_s.size(); i++){
            if(this->game_g->player_s.at(i).name == this->name){
                this->game_g->player_s.at(i).move = Income;
            }
        }
        this-> game_g->tt = p.game_g->names.at((unsigned long)t);
        this->c+=1;
        this->move = Income;
    }
    void Player::foreign_aid(){
        Player p = *this;
        if(p.game_g->names.size() <2){
            throw "to lower players";
        }
        if(p.c > TEN){
            throw "to many coins";
        }
        p.game_g->started = false;
        std::vector<string>::iterator it = std::find(p.game_g->names.begin(), p.game_g->names.end(), p.name);
        int index = std::distance(p.game_g->names.begin(), it);
        int ind = index+1;
        int si = (int) p.game_g->names.size();
        int t = ind % si;
        if(p.name != p.game_g->tt){
            throw "turn jump!";
        }
        this-> game_g->tt = p.game_g->names.at((unsigned long)t);
        this->c+=2;
        this->move = Foreign_aid;
    }
    void Player::coup(Player &p){
        if(p.dead){
            throw "already dead";
        }
        if(this->c >= SEVEN){
            p.dead =true;
            p.game_g->started = false;
            std::vector<string>::iterator it1 = std::find(p.game_g->names.begin(), p.game_g->names.end(), p.name);
            this->game_g->names.erase(it1);
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
            this->c-=SEVEN;
            this->move = Coup;
        }
        else{
            throw "not enoth coins";
        }
    }
    std::string Player::role(){
        return this->r;
    }
    int Player::coins(){
        return this->c;
    }
}