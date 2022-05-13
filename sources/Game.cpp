#include "Player.hpp"

namespace coup{
    std::vector<std::string> Game::players() const{
            return this->names;
    }
    std::string Game::turn() const{
        return this->tt;
    }
    std::string Game::winner(){  
        if(this->started){
            throw "game in progress";
        }
        if(this->names.size() == 1){
            return this->names.at(0);
        }
        throw "game in progress";
    }
}