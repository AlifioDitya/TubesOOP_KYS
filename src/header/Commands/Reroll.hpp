// Reroll.hpp
#ifndef REROLL_HPP
#define REROLL_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Reroll : public Commands {
public:
    // ctor
    Reroll();

    // Executes Reroll
    bool executeCommand(CandyGameState& gameState);
};

#endif
