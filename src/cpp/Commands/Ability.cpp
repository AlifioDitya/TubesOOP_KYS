// Abilityless.cpp
#include "../../header/Commands/Ability.hpp"
#include "../../header/Exception/CommandException.hpp"
#include <map>

using std::map;

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
    if (gameState.getCurrentTurnPlayer().hasUsedAbility()) {
        throw UsedAbility(abilityType);
    }
}

AbilityTypes Ability::parseAbility(string abilityString) {
    // Convert the command string to lowercase for case-insensitive comparison
    transform(abilityString.begin(), abilityString.end(), abilityString.begin(), [](unsigned char c){ return tolower(c); });

    // Map the command string to its equivalent CmdTypes
    map<string, AbilityTypes> abilityMap = {
        {"re-roll",AbilityTypes::Reroll},
        {"quadruple", AbilityTypes::Quadruple},
        {"quarter", AbilityTypes::Quarter},
        {"reverse", AbilityTypes::Reverse},
        {"swapcard", AbilityTypes::SwapCard},
        {"switch", AbilityTypes::Switch},
        {"abilityless", AbilityTypes::Abilityless}
    };

    // Check if the command string is a valid command
    if (abilityMap.find(abilityString) == abilityMap.end()) {
        throw "Input command tidak valid.\n";
    }

    return abilityMap[abilityString];
    
}

string Ability::parseAbility(AbilityTypes ability) {

    // Map the command to its equivalent string
    map<AbilityTypes, string> abilityMap = {
        {AbilityTypes::Reroll, "reroll"},
        {AbilityTypes::Quadruple, "quadruple"},
        {AbilityTypes::Quarter, "quarter"},
        {AbilityTypes::Reverse, "reverse"},
        {AbilityTypes::SwapCard, "swapcard"},
        {AbilityTypes::Switch, "switch"},
        {AbilityTypes::Abilityless, "abilityless"}
    };

    return abilityMap[ability];
    
}
