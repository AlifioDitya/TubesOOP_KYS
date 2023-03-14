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
    int startingPlayerId;
    Player roundWinner;

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
    int getStartingPlayerId();
    Player getRoundWinner();

    // ========== Predicates ==========


    // ========== Setters ==========
    void setWinningList(const vector<Player>&);

    // move to next player turn
    void setNextTurn();

    // Set the starting player for next round
    void setStartingPlayer(Player);

    // Set temporary round winner, return true if the current player is current winner
    bool updateRoundWinner();

    // ========== Other Methods ==========

    // move player in winningList to playerList
    void moveWinningList();

    // move current player to winningList
    void moveToWinningList();

};

#endif