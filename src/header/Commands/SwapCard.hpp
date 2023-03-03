// SwapCard.hpp
#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"

class SwapCard : public Ability {
public:
    // ctor
    SwapCard();

    // Executes SwapCard
    void executeCommand(CandyGameState& gameState);
};

#endif
