// Reroll.hpp
#ifndef REROLL_HPP
#define REROLL_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Reroll : public Commands {
public:
    // ctor
    Reroll();

    // dtor
    ~Reroll();

    // Executes Reroll
    void executeCommand(GameState& gameState);
};

#endif
