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
    GameState(vector<T>, int, int, int, TableCard, DeckCard<Card>);

    // cctor
    GameState(const GameState&);

    // dtor
    ~GameState();

    // Setters
    void setPlayerList(const vector<T>&);

    void setCurrentTurnIdx(int);

    void setRound(int);

    void setPointPool(int);

    void setTableCards(const TableCard&);

    void setDeckCards(const DeckCard<Card>&);

    void setNextTurn();

    // Getters
    vector<T> getPlayerList() const;

    T& getCurrentTurnPlayer();

    T& getPlayerRefAt(int);

    int getCurrentTurnIdx() const;

    int getRound() const;

    int getPointPool() const;

    TableCard& getTableCards();

    DeckCard<Card>& getDeckCards();

    int getPlayerIdx(int id) const;

    // Method to print player list
    void printPlayerList() const;

    void printPlayerList(const vector<T>& playerVec) const;

    // virtual int getWinnerIndex() const = 0;
};

#include "../../cpp/GameEnvironment/GameState.cpp"

#endif