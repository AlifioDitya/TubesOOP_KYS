#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Double : public Commands {
public:
    // ctor
    Double();

    // Executes double
    bool executeCommand(GameState& gameState);
};

#endif
