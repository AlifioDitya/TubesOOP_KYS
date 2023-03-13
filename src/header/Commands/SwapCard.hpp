// SwapCard.hpp
#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "PlayerInvolvedAbility.hpp"

class SwapCard : public PlayerInvolvedAbility {
private:
    int selectCard(string playerName);
public:
    // ctor
    SwapCard();

    // ========== Methods ==========
    
    // Executes SwapCard
    void executeCommand(CandyGameState& gameState);
};

#endif
