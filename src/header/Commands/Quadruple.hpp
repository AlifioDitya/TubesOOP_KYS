#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Quadruple : public Ability {
public:
    // ctor
    Quadruple();

    // Executes Quadruple
    void executeCommand(CandyGameState& gameState);
};

#endif
