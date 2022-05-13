#include "Player.hpp"
using namespace std;
namespace coup
{
    Player::Player(Game &game, string const &name){
        if(game.names.size()+1 > SIX){
            throw std::out_of_range{"To many players"};
        }
        this->dead = false;
        this->arch = this;
        this->place=-1;
        this->name = name; 
        this->move = No_move;
        this->c=0;
        this->game_g = &game;
        game.started = true;
        game.names.push_back(this->name);
        game.player_s.push_back(*this);
        for(unsigned long i = 0 ; i < game.player_s.size(); i++){
            if(game.player_s.at(i).move != No_move){
                throw "game started";
            }
            game.tt = game.names.at(0);
            game.player_s.at(i).game_g = &game;
        }
    }
    void Player::income(){
        this->calc_turn();
        this->income_aid(Income);
        for(unsigned long i = 0 ; i < this->game_g->player_s.size(); i++){
            if(this->game_g->player_s.at(i).name == this->name){
                this->game_g->player_s.at(i).move = Income;
            }
        }
    }
    void Player::foreign_aid(){
        if(this->c > TEN){
            throw "to many coins";
        }
        this->income_aid(Foreign_aid);
        this->calc_turn();
    }
    void Player::coup(Player &p){
        if(p.dead){
            throw "already dead";
        }
        if(this->c >= SEVEN){
            p.dead =true;
            std::vector<string>::iterator it1 = std::find(p.game_g->names.begin(), p.game_g->names.end(), p.name);
            this->game_g->names.erase(it1);
            this->calc_turn();
            this->c-=SEVEN;
            this->move = Coup;
        }
        else{
            throw "not enough coins";
        }
    }
    void Player::income_aid(int m){
        if(this->game_g->names.size() <2){
            throw "to lower players";
        }
        int con = 0;
        if(m == Income){
            con = 1;
        }
        else{
            con = 2;
        }
        this->c+=con;
        this->move = m;
    }
    void Player::calc_turn() const{
        this->game_g->started = false;
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
    std::string Player::role(){
        return this->r;
    }
    int Player::coins(){
        return this->c;
    }
}