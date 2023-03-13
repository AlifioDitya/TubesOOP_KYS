#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "Commands.hpp"

class Double : public Commands {
public:
    // ctor
    Double();

    // ========== Methods ==========
    
    // Executes double
    void executeCommand(CandyGameState& gameState);
};

#endif
