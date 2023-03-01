// Next.hpp
// Next.hpp
#ifndef NEXT_HPP
#define NEXT_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Next : public Commands {
public:
    // ctor
    Next();

    // dtor
    ~Next();

    // Executes next
    bool executeCommand(GameState& gameState);
};

#endif
