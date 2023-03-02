// Abilityless.hpp
#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Abilityless : public Commands {
public:
    // ctor
    Abilityless();

    // Executes Abilityless
    bool executeCommand(CandyGameState& gameState);
};

#endif