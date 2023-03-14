/**
*   @file CandyPlayer.hpp
*   @brief Header file for the CandyPlayer class.
*   This file contains the declaration of the CandyPlayer class, which inherits from Player and adds
*   additional properties and methods specific to the game CandyLand.
**/

#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "Player.hpp"
#include "../Cards/Card.hpp"
#include "../../enums/AbilityTypes.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

/**
*   @class CandyPlayer
*   @brief A class representing a player in a candy-themed card game.
*   @extends Player
**/
class CandyPlayer: public Player {
private:
    bool usedAbility;   // Whether a player has used their ability.
    bool nerfed;        // Whether a player has been abilityless due to another player
    uint64_t point;     // The player's points
    AbilityTypes ability; // The player's ability

public:
    /**
    *   @brief Default constructor for the CandyPlayer class.
    **/
    CandyPlayer();

    /**
    *   @brief Constructor for the CandyPlayer class with specified parameters.
    *   @param id The player's ID.
    *   @param hand A vector of Cards representing the player's hand.
    *   @param point The player's points.
    *   @param name The player's name.
    *   @param hasPlayed Whether the player has played a card in the current round.
    **/
    CandyPlayer(int id, const vector<Card>& hand, uint64_t point, string name, bool hasPlayed);

    
    /**
     * @brief Copy constructor for the CandyPlayer class.
     * @param other The CandyPlayer object to be copied.
     */
    CandyPlayer(const CandyPlayer&);

    /**
     * @brief Overloaded assignment operator for the CandyPlayer class.
     * @param other The CandyPlayer object to be assigned.
     * @return A reference to the assigned CandyPlayer object.
     */
    CandyPlayer& operator=(const CandyPlayer&);

    /**
     * @brief Overloaded less-than operator for the CandyPlayer class.
     * @param other The CandyPlayer object to be compared with.
     * @return True if this player's ID is less than the other player's ID, false otherwise.
     */
    bool operator<(const CandyPlayer& other);

    /**
     * @brief Overloaded more-than operator for the CandyPlayer class.
     * @param other The CandyPlayer object to be compared with.
     * @return True if this player's ID is more than the other player's ID, false otherwise.
     */
    bool operator>(const CandyPlayer& other);

    /**
    *  @brief Setter if a player has used their ability.
    *  @param abilityUsed a boolean value to set a player's ability usage status.
    **/
    void setAbilityUsed(bool);

    /**
    *  @brief Setter if a player has been set abilityless card by another player.
    *  @param nerfed a boolean value to set a player's abilityless status.
    **/
    void setNerfed(bool);

    /**
    *  @brief Setter for ability.
    *  @param ability an AbilityTypes type to set the specific ability to used.
    **/
    void setAbility(AbilityTypes);

    /**
    *  @brief Getter for ability.
    *  @return an AbilityTypes type object.
    **/
    AbilityTypes getAbility();

    /**
    *  @brief Predicates to check if a player has a specific ability.
    *  @return a boolean value indicating a player has the ability specified.
    **/
    bool hasAbility(AbilityTypes) const;
    
    /**
    *  @brief Predicates to check if a player has used a specific ability.
    *  @return a boolean value indicating a player has used the ability specified.
    **/
    bool hasUsedAbility() const;

    /**
    *  @brief Predicates to check if a player has been set abilityless by another player.
    *  @return a boolean value indicating a player's abilityless status.
    **/
    bool isNerfed() const;

    /**
    *  @brief Getter for points.
    *  @return an unsigned integer of the points of a player.
    **/
    uint64_t getPoint() const;

    /**
    *  @brief An interface for getPoint() method.
    *  @return an unsigned integer of a value.
    **/
    uint64_t getValue() const;

    /**
    *  @brief Add points to a player.
    *  @param point an unsigned integer of points to be added
    **/
    void addPoint(uint64_t);
    
    /**
    *  @brief Method to switch cards with another player.
    **/
    void switchCards(CandyPlayer&);

    /**
    *  @brief Method to switch a specific card with another player.
    **/
    void switchCards(int idx1, int idx2, CandyPlayer& other);
};

#endif