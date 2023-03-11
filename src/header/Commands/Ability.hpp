// Abilityless.hpp
#ifndef ABILITY_HPP
#define ABILITY_HPP

#include "Commands.hpp"

class Ability : public Commands {

protected:
    AbilityTypes abilityType;

    void validateAbility(CandyGameState& gameState);
public:

    static AbilityTypes parseAbility(string);
    static string parseAbility(AbilityTypes);

};

#endif