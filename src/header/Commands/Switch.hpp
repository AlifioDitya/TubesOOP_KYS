// Switch.hpp
#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "PlayerInvolvedAbility.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class Switch : public PlayerInvolvedAbility {
public:
    // ctor
    Switch();

    // Executes Switch
    void executeCommand(CandyGameState& gameState);
};

#endif
