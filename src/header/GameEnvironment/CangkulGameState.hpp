// GameState.hpp
#ifndef CANGKULGAMESTATE_HPP
#define CANGKULGAMESTATE_HPP

#include "Player.hpp"
#include "GameState.hpp"
#include "GameDeckCard.hpp"

#include <vector>
#include <deque>

using std::vector;
using std::deque;

class CangkulGameState: public GameState<Player> {
private:
    deque<Player> winningList;

public:
    // Default ctor
    CangkulGameState();

    // Specified ctor
    CangkulGameState(const vector<Player>& playerList, int roundNum, const TableCard& tableCard, const GameDeckCard& deckCard);

    // cctor
    CangkulGameState(const CangkulGameState&);

    // dtor
    ~CangkulGameState();

    // ========== Getters ==========

    vector<Player> getWinningList();
    // ========== Predicates ==========


    // ========== Setters ==========

    void setWinningList(const vector<Player>&);

    // move to next player turn
    void setNextTurn();

    // ========== Other Methods ==========

    // move player in winningList to playerList
    void moveWinningList();

    // move current player to winningList
    void moveToWinningList();

};

#endif