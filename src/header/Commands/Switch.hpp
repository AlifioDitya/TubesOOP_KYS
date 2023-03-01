// Switch.hpp
#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class Switch : public Commands {
public:
    // ctor
    Switch();

    // Executes Switch
    bool executeCommand(GameState& gameState);
};

#endif
