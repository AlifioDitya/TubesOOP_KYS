// Reverse.hpp
#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Reverse : public Ability {
public:
    // ctor
    Reverse();

    // Executes Reverse
    void executeCommand(CandyGameState& gameState);
};

#endif
