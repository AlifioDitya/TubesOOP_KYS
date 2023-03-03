// GameState.hpp
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Player.hpp"
#include "DeckCard.hpp"
#include "TableCard.hpp"
#include <vector>

using std::vector;

template <class T>
class GameState {
protected:
    vector<T> playerList;
    int currentTurnIdx;
    int round;
    int pointPool;
    TableCard tableCards;
    DeckCard deckCards;
    
public:
    // Default ctor
    GameState();

    // Specified ctor
    GameState(vector<T>, int, int, int, TableCard, DeckCard);

    // cctor
    GameState(const GameState&);

    // dtor
    ~GameState();

    // Setters
    void setPlayerList(vector<T>);

    void setCurrentTurnIdx(int);

    void setRound(int);

    void setPointPool(int);

    void setTableCards(TableCard);

    void setDeckCards(DeckCard);

    // Getters
    vector<T> getPlayerList() const;

    T& getCurrentTurnPlayer();

    T& getPlayerRefAt(int);

    int getCurrentTurnIdx() const;

    int getRound() const;

    int getPointPool() const;

    TableCard& getTableCards();

    DeckCard& getDeckCards();

    // Method to print player list
    void printPlayerList() const;

    void printPlayerList(vector<T> playerVec) const;
};

#include "../../cpp/GameEnvironment/GameState.cpp"

#endif