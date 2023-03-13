// GameManager.hpp
#ifndef CANDYGAMEMANAGER_HPP
#define CANDYGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CandyGameState.hpp"
#include "../Commands/Commands.hpp"

#include <map>

using std::map;

class CandyGameManager: public GameManager {
    private:
    map<CmdTypes, Commands*> actions;
    map<AbilityTypes, class Ability*> abilities;
    CandyGameState gameState;

    // ========== Private Methods ==========
    
    // return initial player list with input name
    vector<CandyPlayer> getInitialPlayerList(int playerNum) const;
    // get command input from user
    Commands* getPlayerCommand();
    // initiate deck card (random or file input)
    void inititateDeck();
    // start round
    void startRound();
    // start subgame
    void startSubGame();

    template<class T>
    // get object with highest value from getValue() method member
    T getMax(vector<T>& list) {
        // asumsi list.size() > 0

        T maxElmt = list[0];

        for (auto i = list.begin() + 1; i != list.end(); i++)
        {
            if (i->getValue() > maxElmt.getValue()) maxElmt = *i;
        }
        
        return maxElmt;
    }

    public:

    // Ctor
    CandyGameManager();
    // Dtor
    ~CandyGameManager();

    // ========== Methods ==========

    // start whole game
    void startGame();    

};

#endif