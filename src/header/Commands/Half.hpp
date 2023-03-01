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
    bool executeCommand(GameState& gameState);
};

#endif