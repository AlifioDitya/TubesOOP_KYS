// GameManager.hpp
#ifndef CANDYGAMEMANAGER_HPP
#define CANDYGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CandyGameState.hpp"

class CandyGameManager: public GameManager {
    private:
    
    vector<CandyPlayer> getInitialPlayerList(int playerNum);
    CandyGameState gameState;

    void inititateDeck();
    void startRound();
    void startSubGame();

    public:

    void startGame();
    

};

#endif