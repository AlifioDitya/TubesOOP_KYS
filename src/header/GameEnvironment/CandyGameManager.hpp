// GameManager.hpp
#ifndef CANDYGAMEMANAGER_HPP
#define CANDYGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CandyGameState.hpp"

class CandyGameManager: public GameManager {
    private:
    
    CandyGameState gameState;
    void inititateNewRound();
    void inititateDeck();


    public:

    void initateGame();
    void startGame();
    

};

#endif