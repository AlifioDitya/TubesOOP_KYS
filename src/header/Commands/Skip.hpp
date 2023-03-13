// Skip.hpp
#ifndef SKIP_HPP
#define SKIP_HPP

#include "CangkulCommand.hpp"

class Skip : public CangkulCommand {

private:
    void validateCommand(CangkulGameState&);

public:
    // ctor
    Skip();

    // ========== Methods ==========
    
    // Executes next
    void executeCommand(CangkulGameState& gameState);
};

#endif