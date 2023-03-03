// Switch.hpp
#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Switch : public Ability {
public:
    // ctor
    Switch();

    // Executes Switch
    void executeCommand(CandyGameState& gameState);
};

#endif
