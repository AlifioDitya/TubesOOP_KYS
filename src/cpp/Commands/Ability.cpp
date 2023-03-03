// Abilityless.cpp
#include "../../header/Commands/Ability.hpp"
#include "../../header/Exception/CommandException.h"


void Ability::validateAbility(CandyGameState& gameState) {

    CandyPlayer currentPlayer = gameState.getCurrentTurnPlayer();
    // check if current player has matching ability
    if (!currentPlayer.hasAbility(abilityType)) {
        throw MissingAbility(abilityType);
    }

    // jika ability sudah dimatikan lawan
    if (currentPlayer.isNerfed())
    {
        throw NerfedAbility();
    }

    // check if current player hasn't used the ability
    if (gameState.getCurrentTurnPlayer().hasUsedAbility(abilityType)) {
        throw UsedAbility(abilityType);
    }
}
