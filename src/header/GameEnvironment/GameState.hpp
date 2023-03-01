// GameState.hpp
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Player.hpp"
#include "DeckCard.hpp"
#include "TableCard.hpp"
#include <vector>

using std::vector;

class GameState {
private:
    vector<Player> playerList;
    int currentTurnIdx;
    int round;
    int pointPool;
    TableCard tableCards;
    DeckCard deckCards;
    
public:
    // Default ctor
    GameState();

    // Specified ctor
    GameState(vector<Player>, int, int, int, TableCard, DeckCard);

    // cctor
    GameState(const GameState&);

    // dtor
    ~GameState();

    // Setters
    void setPlayerList(vector<Player>);

    void setCurrentTurnIdx(int);

    void setRound(int);

    void setPointPool(int);

    void setTableCards(TableCard);

    void setDeckCards(DeckCard);

    // Getters
    vector<Player>& getPlayerList();

    Player& getCurrentTurnPlayer();

    int getCurrentTurnIdx();

    int getRound();

    int getPointPool();

    TableCard& getTableCards();

    DeckCard& getDeckCards();

    // Method to print player list
    void printPlayerList();
};

#endif