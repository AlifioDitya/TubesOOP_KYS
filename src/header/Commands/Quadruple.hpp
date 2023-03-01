#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Quadruple : public Commands {
public:
    // ctor
    Quadruple();

    // dtor
    virtual ~Quadruple();

    // Executes Quadruple
    bool executeCommand(GameState& gameState);
};

#endif
