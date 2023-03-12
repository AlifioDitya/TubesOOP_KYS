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

    // Executes SwapCard
    void executeCommand(CandyGameState& gameState);
};

#endif
