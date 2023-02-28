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
    int points;
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

    void setCurrentTurn(int);

    void setRound(int);

    void setPoints(int);

    void setTableCards(TableCard);

    void setDeckCards(DeckCard);

    // Getters
    vector<Player> getPlayerList();

    int getCurrentTurn();

    int getRound();

    int getPoints();

    TableCard getTableCards();

    DeckCard getDeckCards();
};

#endif