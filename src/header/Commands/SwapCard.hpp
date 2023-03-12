// SwapCard.hpp
#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "PlayerInvolvedAbility.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class SwapCard : public PlayerInvolvedAbility {
private:
    int SwapCard::selectCard(string playerName);
public:
    // ctor
    SwapCard();

    // Executes SwapCard
    void executeCommand(CandyGameState& gameState);
};

#endif
