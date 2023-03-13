// GameState.hpp
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <algorithm>
#include <deque>
#include <iostream>

#include "GameDeckCard.hpp"
#include "Player.hpp"
#include "TableCard.hpp"

using std::cout;
using std::deque;
using std::endl;
using std::find_if;
using std::sort;
using std::greater;

template <class T>
class GameState {
   protected:
    deque<T> playerList;
    int round;
    TableCard tableCards;
    GameDeckCard deckCards;

   public:
    // Default ctor
    GameState() {
        // Initialize default values
        playerList = deque<T>();

        // player giliran saat ini selalu indeks 0
        // currentTurnIdx = 0;

        round = 1;
        tableCards = TableCard();
        deckCards = GameDeckCard();
    };

    // Specified ctor
    GameState(const vector<T>& playerList, int roundNum, const TableCard& tableCard, const GameDeckCard& deckCard) {
        this->playerList = deque<T>(playerList.begin(), playerList.end());

        // player giliran saat ini selalu indeks 0
        // currentTurnIdx = currentTurn;
        this->round = roundNum;
        this->tableCards = tableCard;
        this->deckCards = deckCard;
    };

    // cctor
    GameState(const GameState<T>& gameState) {
        playerList = gameState.playerList;
        round = gameState.round;
        tableCards = gameState.tableCards;
        deckCards = gameState.deckCards;
    };

    // dtor
    ~GameState(){};

    // ========= Setters ==========

    // setter for playerList
    void setPlayerList(const vector<T>& playerList) {
        this->playerList = deque<T>(playerList.begin(), playerList.end());
    };

    // setter for round
    void setRound(int roundNum) {
        round = roundNum;
    };

    // setter for tableCards
    void setTableCards(const vector<Card>& cards) {
        tableCards.setCards(cards);
    }

    // setter for deckCards
    void setDeckCards(const vector<Card>& cards) {
        deckCards.setCards(cards);
    }

    // setter for playerList order with front player being sent to the back of deque
    virtual void setNextTurn() {
        T& currentPlayer = getCurrentTurnPlayer();
        currentPlayer.setHasPlayed(true);

        if (hasAllPlayed()) {
            skipCurrentPlayer();
        }

        else {
            while (playerList[0].hasPlayedThisRound()) {
                skipCurrentPlayer();
            }
        }
    }

    // sent front player to the back of deque
    void skipCurrentPlayer() {
        T player = playerList[0];
        playerList.pop_front();
        playerList.push_back(player);
    }

    // set all player to has not played
    void setAllNotPlayed() {
        for (long unsigned int i = 0; i < getPlayerList().size(); i++) {
            T& player = getPlayerRefAt(i);

            player.setHasPlayed(false);
        }
    };

    // ========= Getters ==========

    // return playerList in vector
    vector<T> getPlayerList() const {
        return vector<T>(playerList.begin(), playerList.end());
    };

    // return reference to front player
    T& getCurrentTurnPlayer() {
        return playerList.front();
    };

    // return reference of player at certain idx
    T& getPlayerRefAt(int idx) {
        return playerList[idx];
    }

    // return current round
    int getRound() const {
        return round;
    }

    // return reference to tableCards
    TableCard& getTableCards() {
        return tableCards;
    }

    // return reference to deckCards
    GameDeckCard& getDeckCards() {
        return deckCards;
    }

    // return true of all player has played in this round
    bool hasAllPlayed() const {
        for (auto player : playerList) {
            if (!player.hasPlayedThisRound())
                return false;
        }

        return true;
    }

    // return indeks of player with certain id
    int getPlayerIdx(int id) const {
        for (long unsigned int i = 0; i < playerList.size(); i++) {
            if (playerList[i].getId() == id) {
                return i;
            }
        }

        return -1;
    }

    // ========= Other Methods ==========

    // Methods for printing remaining player turn in this round
    void printRemainingTurn() const {

        auto i = playerList.begin() + 1;

        while (i != playerList.end() && i->hasPlayedThisRound()) i++;

        if (i == playerList.end()) {
            cout << "(Tidak ada giliran player lain pada round ini)";
        }

        else
        {
            while (i != playerList.end() && !i->hasPlayedThisRound())
            {
                cout << "<" << i->getName()<< "> ";
                i++;
            }
        }

        cout << endl;
    }

    // Methods for printing current player list
    void printPlayerList() const {
        for (long unsigned int i = 0; i < playerList.size(); i++) {
            cout << i + 1 << ". " << playerList[i].getName() << endl;
        }
    }

    // method for printing input player list
    void printPlayerList(const vector<T>& playerVec) const {
        for (long unsigned int i = 0; i < playerVec.size(); i++) {
            cout << i + 1 << ". " << playerVec[i].getName() << endl;
        }
    }


};

#endif