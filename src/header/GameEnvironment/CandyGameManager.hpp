/**
*   @file CandyGameManager.hpp
*   @brief Header file for the CandyGameManager class.
**/

#ifndef CANDYGAMEMANAGER_HPP
#define CANDYGAMEMANAGER_HPP

#include <map>

#include "../Commands/Commands.hpp"
#include "CandyGameState.hpp"
#include "GameManager.hpp"

using std::map;

<<<<<<< HEAD
class CandyGameManager : public GameManager {
   private:
=======
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
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2
    map<CmdTypes, Commands*> actions;

<<<<<<< HEAD
    // private methods
=======
    /**
        @brief Map of available abilities for the Candy game.
    **/
    map<AbilityTypes, class Ability*> abilities;

    /**
        @brief Representing the game state for the Candy game.
    **/
    CandyGameState gameState;
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2

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

<<<<<<< HEAD
    Combination* findComboType(const vector<Card> tableCards, const vector<Card> handCards);

    void inititateDeck();
=======
    /**
    *   @brief Method to initialize the deck card for the game.
    **/
    void initiateDeck();

    /**
    *   @brief Method start round of the game.
    **/
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2
    void startRound();

    /**
    *   @brief Method to start a sub-game of the Candy game.
    **/
    void startSubGame();

<<<<<<< HEAD
    template <class T>
=======
    /**
    *   @brief Template method to get the object with the highest value from a vector of objects with getValue() method member.
    *   @tparam T the type of objects in the vector.
    *   @param[in] list vector of objects to search for the maximum value.
    *   @return the object with the maximum value.
    **/
    template<class T>
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2
    T getMax(vector<T>& list) {

        T maxElmt = list[0];

        for (auto i = list.begin() + 1; i != list.end(); i++) {
<<<<<<< HEAD
            if (i->getValue() > maxElmt.getValue())
                maxElmt = *i;
=======
            if (i->getValue() > maxElmt.getValue()) maxElmt = *i;
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2
        }

        return maxElmt;
    }

<<<<<<< HEAD
   public:
=======
public:
    /**
    *   @brief Default constructor for CandyGameManager class.
    **/
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2
    CandyGameManager();

    /**
    *   @brief Destructor for CandyGameManager class.
    **/
    ~CandyGameManager();
<<<<<<< HEAD
    void startGame();
=======

    // ========== Methods ==========

    /**
    *   @brief Method to start the Candy game.
    **/
    void startGame();

    /**
    *   @brief Integer value representing the number of initial draws for the game.
    **/
    static int initialDraw;
>>>>>>> 331a2a6218ee26d91c50dc378ad37fd696ea21c2
};

#endif