// SwapCard.hpp
#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"
#include "../GameEnvironment/CandyGameState.hpp"
#include <string>

class SwapCard : public Ability {
private:

public:
    // ctor
    SwapCard();

    // Executes SwapCard
    void executeCommand(CandyGameState& gameState);
};

#endif
