// Quadruple.hpp
#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

class Quadruple : public Ability {
public:
    // ctor
    Quadruple();

    // ========== Methods ==========
    
    // Executes Quadruple
    void executeCommand(CandyGameState& gameState);
};

#endif
