/**
 * @file GameState.hpp
 * @brief Header file for the GameState class that holds the state of a game.
 * 
 */
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

/**
 * @class GameState
 * @brief Class that holds the state of a game.
 * 
 * @tparam T Element type of the players in the game.
 */
template<class T>
class GameState {
protected:
    /**
     * @brief Deque that contains the list of players
     *
     */
    deque<T> playerList;

    /**
     * @brief an integer value denoting the current round
     * 
     */
    int round;

    /**
     * @brief The table cards in the game
     * 
     */
    TableCard tableCards;

    /**
     * @brief The deck cards in the game
     * 
     */
    GameDeckCard deckCards;

public:
    /**
     * @brief Construct a new Game State object
     * 
     */
    GameState() {
        // Initialize default values
        playerList = deque<T>();

        // player giliran saat ini selalu indeks 0
        // currentTurnIdx = 0;

        round = 1;
        tableCards = TableCard();
        deckCards = GameDeckCard();
    };

    /**
     * @brief Constructs a new Game State object with specified parameters
     * 
     * @param playerList a list of players
     * @param roundNum the round number
     * @param tableCard the table cards in game
     * @param deckCard the deck cards in game
     */
    GameState(const vector<T>& playerList, int roundNum, const TableCard& tableCard, const GameDeckCard& deckCard) {
        this->playerList = deque<T>(playerList.begin(), playerList.end());

        // player giliran saat ini selalu indeks 0
        // currentTurnIdx = currentTurn;
        this->round = roundNum;
        this->tableCards = tableCard;
        this->deckCards = deckCard;
    };

    /**
     * @brief Copy constructs a new Game State object
     * 
     * @param gameState a GameState object to be copied
     */
    GameState(const GameState<T>& gameState) {
        playerList = gameState.playerList;
        round = gameState.round;
        tableCards = gameState.tableCards;
        deckCards = gameState.deckCards;
    };

    /**
     * @brief Destroy the Game State object
     * 
     */
    ~GameState() {};

    /**
     * @brief Set the Player List
     * 
     * @param playerList List of players in the game
     */
    void setPlayerList(const vector<T>& playerList) {
        this->playerList = deque<T>(playerList.begin(), playerList.end());
    };

    /**
     * @brief Set the Round number
     * 
     * @param roundNum the current round number
     */
    void setRound(int roundNum) {
        round = roundNum;
    };

    /**
     * @brief Set the Table Cards
     * 
     * @param cards List of cards on the table
     */
    void setTableCards(const vector<Card>& cards) {
        tableCards.setCards(cards);
    }

    /**
     * @brief Set the Deck Cards
     * 
     * @param cards List of cards on the deck
     */
    void setDeckCards(const vector<Card>& cards) {
        deckCards.setCards(cards);
    }

    // setter for playerList order with front player being sent to the back of deque
    /**
     * @brief Set the Next Turn player.
     * the playerList is ordered with the current front player being sent to the back of deque.
     * 
     */
    virtual void setNextTurn() {
        T& currentPlayer = getCurrentTurnPlayer();
        currentPlayer.setHasPlayed(true);

        if (hasAllPlayed()) {
            skipCurrentPlayer();
        } else {
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

    /**
     * @brief Get the Player List
     * 
     * @return the List of players in game
     */
    vector<T> getPlayerList() const {
        return vector<T>(playerList.begin(), playerList.end());
    };

    /**
     * @brief Get the reference to the Current Turn Player
     * 
     * @return Reference to the player that holds the current turn.
     */
    T& getCurrentTurnPlayer() {
        return playerList.front();
    };

    /**
     * @brief Get the reference to the Player at a certain index in the playerList
     * 
     * @return Reference to the player in the specified index.
     */
    T& getPlayerRefAt(int idx) {
        return playerList[idx];
    }

    /**
     * @brief Get the current round number
     * 
     * @return an integer value denoting the round number.
     */
    int getRound() const {
        return round;
    }

    /**
     * @brief Get a reference to the Table Cards
     * 
     * @return a Reference to the table cards.
     */
    TableCard& getTableCards() {
        return tableCards;
    }

    /**
     * @brief Get a reference to the Deck Cards
     * 
     * @return a Reference to the deck cards.
     */
    GameDeckCard& getDeckCards() {
        return deckCards;
    }

    /**
     * @brief Predicate to check if all players has played the current round.
     * 
     * @return true if all of the players has played the round.
     * @return false otherwise.
     */
    bool hasAllPlayed() const {
        for (auto player: playerList) {
            if (!player.hasPlayedThisRound())
                return false;
        }

        return true;
    }

    /**
     * @brief Get the Index of a player with a certain Id
     * 
     * @param id Player Id to be specified
     * @return Index of a player with the specified index if index is valid. Returns -1 otherwise.
     */
    int getPlayerIdx(int id) const {
        for (long unsigned int i = 0; i < playerList.size(); i++) {
            if (playerList[i].getId() == id) {
                return i;
            }
        }

        return -1;
    }

    /**
     * @brief Prints the order of players on the remaining turn
     * 
     */
    void printRemainingTurn() const {

        auto i = playerList.begin() + 1;

        while (i != playerList.end() && i->hasPlayedThisRound()) i++;

        if (i == playerList.end()) {
            cout << "(Tidak ada giliran player lain pada round ini)";
        } else {
            while (i != playerList.end() && !i->hasPlayedThisRound()) {
                cout << "<" << i->getName() << "> ";
                i++;
            }
        }

        cout << endl;
    }

    /**
     * @brief Prints the current player list
     * 
     */
    void printPlayerList() const {
        for (long unsigned int i = 0; i < playerList.size(); i++) {
            cout << i + 1 << ". " << playerList[i].getName() << endl;
        }
    }

    /**
     * @brief Prints a specified player list
     * 
     * @param playerVec a list of players to be printed
     */
    void printPlayerList(const vector<T>& playerVec) const {
        for (long unsigned int i = 0; i < playerVec.size(); i++) {
            cout << i + 1 << ". " << playerVec[i].getName() << endl;
        }
    }
};

#endif