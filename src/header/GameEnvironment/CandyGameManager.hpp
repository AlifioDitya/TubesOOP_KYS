// GameManager.hpp
#ifndef CANDYGAMEMANAGER_HPP
#define CANDYGAMEMANAGER_HPP

#include "GameManager.hpp"
#include "CandyGameState.hpp"

#include <map>

using std::map;

class CandyGameManager: public GameManager {
    private:
    vector<Commands*> actions;
    map<AbilityTypes, class Ability*> abilities;
    CandyGameState gameState;


    // private methods

    vector<CandyPlayer> getInitialPlayerList(int playerNum);
    Commands* getPlayerCommand();
    void inititateDeck();
    void startRound();
    void startSubGame();

    template<class T>
    T getMax(const vector<T>&);

    public:
    CandyGameManager();
    ~CandyGameManager();
    void startGame();    

};

#endif