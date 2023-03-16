/**
 *   @file CandyGameManager.hpp
 *   @brief Header file for the CandyGameManager class.
 **/

#ifndef CANDYGAMEMANAGER_HPP
#define CANDYGAMEMANAGER_HPP

#include <map>

#include "../Cards/Combination.hpp"
#include "../Commands/Commands.hpp"
#include "CandyGameState.hpp"
#include "GameManager.hpp"

using std::map;

/**
 *   @class CandyGameManager
 *   @brief Class representing the game manager for the Candy game.
 *   @extends GameManager
 **/
class CandyGameManager : public GameManager {
   private:
    /**
        @brief Map of available commands for the Candy game.
    **/
    map<CmdTypes, Commands*> actions;

    /**
        @brief Map of available abilities for the Candy game.
    **/
    map<AbilityTypes, class Ability*> abilities;

    /**
        @brief Representing the game state for the Candy game.
    **/
    CandyGameState gameState;

    /**
     *   @brief Method to get the initial player list for the game.
     *   @param[in] playerNum the number of players for the game.
     *   @return vector of CandyPlayer objects representing the initial player list.
     **/
    vector<CandyPlayer> getInitialPlayerList(int playerNum) const;

    /**
     *`  @brief Method to get the player command from the user.
     *`  @return pointer to a Commands object representing the user's command.
     **/
    Commands* getPlayerCommand();

    /**
     *   @brief Method to get the best possible combination of cards from given lists
     *   @param tableCards list of 5 table cards
     *   @param tableCards list of 2 hand cards
     *   @return Polymorphic Combination pointer of combination type
     **/
    Combination* findComboType(const vector<Card> tableCards, const vector<Card> handCards);

    /**
     *   @brief Method to initialize the deck card for the game.
     **/
    void initiateDeck();

    /**
     *   @brief Method start round of the game.
     **/
    void startRound();

    /**
     *   @brief Method to start a sub-game of the Candy game.
     **/
    void startSubGame();

    /**
     *   @brief Template method to get the object with the highest value from a vector of objects
     *with getValue() method member.
     *   @tparam T the type of objects in the vector.
     *   @param[in] list vector of objects to search for the maximum value.
     *   @return the object with the maximum value.
     **/
    template <class T>
    T getMax(vector<T>& list) {
        T maxElmt = list[0];

        for (auto i = list.begin() + 1; i != list.end(); i++) {
            if ((*i)->getValue() > maxElmt->getValue())
                maxElmt = *i;
        }

        return maxElmt;
    }

   public:
    /**
     *   @brief Default constructor for CandyGameManager class.
     **/
    CandyGameManager();

    /**
     *   @brief Destructor for CandyGameManager class.
     **/
    ~CandyGameManager();

    // ========== Methods ==========

    /**
     *   @brief Method to start the Candy game.
     **/
    void startGame();

    /**
     *   @brief Integer value representing the number of initial draws for the game.
     **/
    static int initialDraw;
};

#endif