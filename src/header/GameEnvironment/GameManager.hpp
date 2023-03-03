// GameManager.hpp
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "GameState.hpp"

class GameManager {
    protected:

    public:

    void initateGame();
    virtual void startGame() = 0;
    

};

#endif