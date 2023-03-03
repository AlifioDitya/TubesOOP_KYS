// Abilityless.hpp
#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Abilityless : public Ability {
public:
    // ctor
    Abilityless();

    // Executes Abilityless
    void executeCommand(CandyGameState& gameState);
};

#endif