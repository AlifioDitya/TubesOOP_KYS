// Quarter.hpp
#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Quarter : public Ability {
public:
    // ctor
    Quarter();

    // Executes Quarter
    void executeCommand(CandyGameState& gameState);
};

#endif