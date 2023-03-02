#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Quadruple : public Commands {
public:
    // ctor
    Quadruple();

    // Executes Quadruple
    bool executeCommand(CandyGameState& gameState);
};

#endif
