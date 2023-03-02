// Quarter.hpp
#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Commands.hpp"
#include "../GameEnvironment/GameState.hpp"
#include "../GameEnvironment/CandyPlayer.hpp"

class Quarter : public Commands {
public:
    // ctor
    Quarter();

    // Executes Quarter
    bool executeCommand(CandyGameState& gameState);
};

#endif