// Reroll.hpp
#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Reroll : public Ability {
public:
    // ctor
    Reroll();

    // Executes Reroll
    void executeCommand(CandyGameState& gameState);
};

#endif
