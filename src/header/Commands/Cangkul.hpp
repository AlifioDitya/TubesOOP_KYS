// Cangkul.hpp
#ifndef CANGKUL_HPP
#define CANGKUL_HPP

#include "CangkulCommand.hpp"

class Cangkul : public CangkulCommand {

private:
    void validateCommand(CangkulGameState&);

public:
    // ctor
    Cangkul();

    // ========== Methods ==========
    
    // Executes next
    void executeCommand(CangkulGameState& gameState);
};

#endif