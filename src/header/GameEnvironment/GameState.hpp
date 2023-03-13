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
    unsigned long long pointPool;
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
        pointPool = 64;
        tableCards = TableCard();
        deckCards = GameDeckCard();
    };

    // Specified ctor
    GameState(const vector<T>& playerList, int roundNum, unsigned long long points, const TableCard& tableCard,
              const GameDeckCard& deckCard) {
        this->playerList = deque<T>(playerList.begin(), playerList.end());

        // player giliran saat ini selalu indeks 0
        // currentTurnIdx = currentTurn;
        this->round = roundNum;
        this->pointPool = points;
        this->tableCards = tableCard;
        this->deckCards = deckCard;
    };

    // cctor
    GameState(const GameState& gameState) {
        playerList = gameState.playerList;
        round = gameState.round;
        pointPool = gameState.pointPool;
        tableCards = gameState.tableCards;
        deckCards = gameState.deckCards;
    };

    // dtor
    ~GameState(){};

    // Setters
    void setPlayerList(const vector<T>& playerList) {
        this->playerList = deque<T>(playerList.begin(), playerList.end());
    };



    void setRound(int roundNum) {
        round = roundNum;
    };

    void setPointPool(unsigned long long points) {
        pointPool = points;
    };

    void setTableCards(const vector<Card>& cards) {
        tableCards.setCards(cards);
    }

    void setDeckCards(const vector<Card>& cards) {
        deckCards.setCards(cards);
    }

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

    // Getters
    vector<T> getPlayerList() const {
        return vector<T>(playerList.begin(), playerList.end());
    };

    T& getCurrentTurnPlayer() {
        return playerList.front();
    };

    T& getPlayerRefAt(int idx) {
        return playerList[idx];
    }

    int getRound() const {
        return round;
    }

    unsigned long long getPointPool() const {
        return pointPool;
    }

    TableCard& getTableCards() {
        return tableCards;
    }

    GameDeckCard& getDeckCards() {
        return deckCards;
    }

    bool hasAllPlayed() const {
        for (auto player : playerList) {
            if (!player.hasPlayedThisRound())
                return false;
        }

        return true;
    }

    int getPlayerIdx(int id) const {
        for (long unsigned int i = 0; i < playerList.size(); i++) {
            if (playerList[i].getId() == id) {
                return i;
            }
        }

        return -1;
    }

    // Methods for printing player turn
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

    void printNextRoundTurn() const {
        auto i = playerList.begin() + 1;
        long unsigned int counter = 0;

        while (counter < playerList.size())
        {
            cout << "<" << i->getName()<< "> ";

            int idx = i - playerList.begin();
            i = playerList.begin() + ((idx + 1) % playerList.size());
            counter++;
        }

        cout << endl;
    }

    // Methods for printing player list
    void printPlayerList() const {
        for (long unsigned int i = 0; i < playerList.size(); i++) {
            cout << i + 1 << ". " << playerList[i].getName() << endl;
        }
    }

    void printPlayerList(const vector<T>& playerVec) const {
        for (long unsigned int i = 0; i < playerVec.size(); i++) {
            cout << i + 1 << ". " << playerVec[i].getName() << endl;
        }
    }

    void printLeaderBoard() const {
        vector<T> list = getPlayerList();

        sort(list.begin(), list.end());

        cout << "Leaderboard :" << endl;
        for (int i = list.size() - 1; i >= 0; i--) {
            cout << "\t" << list.size() - i << ". " << list[i].getName() << ": " << list[i].getPoint() << endl;
        }

    }


};

#endif