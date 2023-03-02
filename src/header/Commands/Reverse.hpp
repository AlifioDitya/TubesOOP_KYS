// Reverse.hpp
#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Reverse : public Commands {
public:
    // ctor
    Reverse();

    // Executes Reverse
    bool executeCommand(CandyGameState& gameState);
};

#endif
