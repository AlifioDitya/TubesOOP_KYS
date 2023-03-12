// Abilityless.hpp
#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "PlayerInvolvedAbility.hpp"

class Abilityless : public PlayerInvolvedAbility {
public:
    // ctor
    Abilityless();

    // Executes Abilityless
    void executeCommand(CandyGameState& gameState);
};

#endif