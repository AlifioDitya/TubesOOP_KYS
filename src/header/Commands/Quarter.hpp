// Quarter.hpp
#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability {
public:
    // ctor
    Quarter();

    // Executes Quarter
    void executeCommand(CandyGameState& gameState);
};

#endif