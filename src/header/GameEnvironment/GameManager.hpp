// GameManager.hpp
#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "GameState.hpp"



class GameManager {
    private:
    
    GameState gameState;

    virtual void checkWinner() = 0;
    virtual void nextRound() = 0;
    virtual void nextTurn() = 0;

    public:

    void initateGame();
    virtual void startGame() = 0;
    

};

#endif