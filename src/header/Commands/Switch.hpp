// Switch.hpp
#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "PlayerInvolvedAbility.hpp"

class Switch : public PlayerInvolvedAbility {
public:
    // ctor
    Switch();

    // ========== Methods ==========
    
    // Executes Switch
    void executeCommand(CandyGameState& gameState);
};

#endif
