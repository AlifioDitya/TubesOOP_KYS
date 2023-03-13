// Abilityless.hpp
#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "Commands.hpp"

class Ability : public Commands {

protected:
    AbilityTypes abilityType;

    // ========== Protected Methods ==========

    // validate ability command by throwing exception if necessary
    void validateAbility(CandyGameState& gameState);

public:

    // ========== Static Methods ==========

    // convert ability string to type
    static AbilityTypes parseAbility(string abilityString);

    // convert ability type to string
    static string parseAbility(AbilityTypes);

};

#endif