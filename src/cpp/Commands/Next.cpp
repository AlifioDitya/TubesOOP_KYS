// Next.cpp
#include "../../header/Commands/Next.hpp"

// Execute method
void Next::executeCommand(GameState& gameState) {
    int nextPlayerIdx = (gameState.getCurrentTurn() + 1) % gameState.getPlayerList().size();
    gameState.setCurrentTurn(nextPlayerIdx);
}