// Next.hpp
#ifndef NEXT_HPP
#define NEXT_HPP

#include "Commands.hpp"

class Next : public Commands {
public:
    // ctor
    Next();

    // Executes next
    void executeCommand(CandyGameState& gameState);
};

#endif
