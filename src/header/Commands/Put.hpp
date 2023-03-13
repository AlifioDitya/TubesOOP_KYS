// Put.hpp
#ifndef PUT_HPP
#define PUT_HPP

#include "CangkulCommand.hpp"

class Put : public CangkulCommand {

private:
    void validateCommand(CangkulGameState&);

public:
    // ctor
    Put();

    // ========== Methods ==========
    
    // Executes next
    void executeCommand(CangkulGameState& gameState);
};

#endif
