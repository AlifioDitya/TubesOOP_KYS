// GameManager.hpp
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "GameState.hpp"

class GameManager {
    protected:
    
    public:
    GameManager();
    virtual void initateGame() = 0;
    virtual void startGame() = 0;
    

};

#endif