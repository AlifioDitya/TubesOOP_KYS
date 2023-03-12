// GameState.hpp
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Player.hpp"
#include "TableCard.hpp"
#include "GameDeckCard.hpp"
#include <deque>

using std::deque;

template <class T>
class GameState {
protected:
    deque<T> playerList;
    // giliran selalu indeks 0
    // int currentTurnIdx;
    int round;
    int pointPool;
    TableCard tableCards;
    GameDeckCard deckCards;
    
public:
    // Default ctor
    GameState();

    // Specified ctor
    GameState(const vector<T>& playerList, int roundNum, int points, const TableCard& tableCard, const GameDeckCard& deckCard);

    // cctor
    GameState(const GameState&);

    // dtor
    ~GameState();

    // Setters
    void setPlayerList(const vector<T>&);

    // void setCurrentTurnIdx(int);

    void setRound(int);

    void setPointPool(int);

    void setTableCards(const vector<Card>&);

    void setDeckCards(const vector<Card>&);

    virtual void setNextTurn();

    void skipCurrentPlayer();
    
    // set all player to has not played
    void setAllNotPlayed();
    // Getters
    vector<T> getPlayerList() const;

    T& getCurrentTurnPlayer();

    T& getPlayerRefAt(int);

    // int getCurrentTurnIdx() const;

    int getRound() const;

    int getPointPool() const;

    bool hasAllPlayed() const;

    TableCard& getTableCards();

    GameDeckCard& getDeckCards();

    int getPlayerIdx(int id) const;

    // Method to print player list
    void printPlayerList() const;

    void printPlayerList(const vector<T>& playerVec) const;

    // virtual int getWinnerIndex() const = 0;
};

#include "../../cpp/GameEnvironment/GameState.cpp"

#endif