// GameManager.hpp
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "GameState.hpp"

class GameManager {
    protected:
    
    virtual void startSubGame() = 0;
    virtual void startRound() = 0;
    public:

    // ========= Methods ==========

    // start whole game
    virtual void startGame() = 0;

};

#endif