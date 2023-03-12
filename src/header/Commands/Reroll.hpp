// Reroll.hpp
#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

class Reroll : public Ability {
public:
    // ctor
    Reroll();

    // Executes Reroll
    void executeCommand(CandyGameState& gameState);
};

#endif
