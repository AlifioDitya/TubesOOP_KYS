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


    // private methods

    vector<CandyPlayer> getInitialPlayerList(int playerNum) const;
    Commands* getPlayerCommand();
    void inititateDeck();
    void startRound();
    void startSubGame();

    template<class T>
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
    CandyGameManager();
    ~CandyGameManager();
    void startGame();    

};

#endif