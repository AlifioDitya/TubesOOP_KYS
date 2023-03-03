// Half.hpp
#ifndef HALF_HPP
#define HALF_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Half : public Commands {
public:
    // ctor
    Half();

    // Executes Half
    void executeCommand(CandyGameState& gameState);
};

#endif