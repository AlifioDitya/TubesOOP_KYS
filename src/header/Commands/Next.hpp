// Next.hpp
#ifndef NEXT_HPP
#define NEXT_HPP

#include "Commands.hpp"

class Next : public Commands {
public:
    // ctor
    Next();

    // ========== Methods ==========
    
    // Executes next
    void executeCommand(CandyGameState& gameState);
};

#endif
