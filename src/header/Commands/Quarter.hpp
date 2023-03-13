// Quarter.hpp
#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability {
public:
    // ctor
    Quarter();

    // ========== Methods ==========
    
    // Executes Quarter
    void executeCommand(CandyGameState& gameState);
};

#endif