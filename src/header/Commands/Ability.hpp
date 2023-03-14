/**
 * @file Ability.hpp
 * @brief Header file for the Ability class.
 * 
 */
#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "Commands.hpp"

/**
 * @class Ability
 * @brief Base class that defines the in-game ability commands
 * @extends Commands
 * 
 */
class Ability : public Commands {

protected:
    AbilityTypes abilityType;

    /**
     * @brief Validate ability command by throwing exception if necessary
     * 
     * @param gameState State of the game to be validated on
     */
    void validateAbility(CandyGameState& gameState);

public:

    /**
     * @brief Converts the ability from string to AbilityTypes
     * 
     * @param abilityString String of ability
     * @return AbilityTypes object
     */
    static AbilityTypes parseAbility(string abilityString);

    /**
     * @brief Converts AbilityTypes object to string
     * 
     * @return string representation of an AbilityTypes object
     */
    static string parseAbility(AbilityTypes);

};

#endif