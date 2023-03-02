// GameState.hpp
#ifndef CANDYGAMESTATE_HPP
#define CANDYGAMESTATE_HPP

#include "CandyPlayer.hpp"
#include "GameState.hpp"
#include "DeckCard.hpp"
#include "TableCard.hpp"
#include <vector>

using std::vector;

class CandyGameState: public GameState {
private:
    vector<CandyPlayer> playerList;
    
public:
    // Default ctor
    CandyGameState();

    // Specified ctor
    CandyGameState(vector<CandyPlayer>, int, int, int, TableCard, DeckCard);

    // cctor
    CandyGameState(const CandyGameState&);

    // dtor
    ~CandyGameState();

    // Setters
    void setPlayerList(vector<CandyPlayer>);

    // Getters
    vector<Player> getPlayerList();

    Player& getCurrentTurnPlayer();

    Player& getPlayerRefAt(int);

    int getCurrentTurnIdx();

    int getRound();

    int getPointPool();

    TableCard& getTableCards();

    DeckCard& getDeckCards();

    // Predicates
    bool hasAllUsedAbility();

    // Method to print player list
    void printPlayerList();

    void printPlayerList(vector<Player> playerVec);
};

#endif