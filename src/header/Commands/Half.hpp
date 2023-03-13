// Half.hpp
#ifndef HALF_HPP
#define HALF_HPP

#include "Commands.hpp"

class Half : public Commands {
public:
    // ctor
    Half();

    // ========== Methods ==========
    
    // Executes Half
    void executeCommand(CandyGameState& gameState);
};

#endif