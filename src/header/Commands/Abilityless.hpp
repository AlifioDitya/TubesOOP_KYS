// Abilityless.hpp
#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "PlayerInvolvedAbility.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Abilityless : public PlayerInvolvedAbility {
public:
    // ctor
    Abilityless();

    // Executes Abilityless
    void executeCommand(CandyGameState& gameState);
};

#endif