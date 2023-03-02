// SwapCard.hpp
#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"

class SwapCard : public Commands {
public:
    // ctor
    SwapCard();

    // Executes SwapCard
    bool executeCommand(CandyGameState& gameState);
};

#endif
