// Next.hpp
#ifndef NEXT_HPP
#define NEXT_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Next : public Commands {
public:
    // Executes next
    void executeCommand(GameState& gameState);
};

#endif
