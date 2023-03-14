/**
 * @file PlayerInvolvedAbility.hpp
 * @brief Header file for the PlayerInvolvedAbility class.
 * 
 */
#ifndef PLAYERINVOLVEDABILITY_HPP
#define PLAYERINVOLVEDABILITY_HPP

#include "Ability.hpp"

/**
 * @class PlayerInvolvedAbility
 * @brief Class that defines the players that are involved in an ability action
 * @extends Ability
 * 
 */
class PlayerInvolvedAbility : public Ability {

protected:

    /**
     * @brief Returns the chosen player index
     * 
     * @param gameState State of the game
     * @param playerList List of players
     * @param label Label to be outputted
     * @return Index of selected player
     */
    int selectPlayer(CandyGameState& gameState, const vector<CandyPlayer>& playerList, string label);

public:


};

#endif