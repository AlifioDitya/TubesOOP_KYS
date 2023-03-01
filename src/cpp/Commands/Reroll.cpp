// Reroll.cpp
#include "../../header/Commands/Reroll.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ctor
Reroll::Reroll() {
    this->command = CmdTypes::Reroll;
}

// dtor
Reroll::~Reroll() {
    // Do nothing
}

// Execute method
void Reroll::executeCommand(GameState& gameState) {
    if (this->command != CmdTypes::Reroll) {
        return;
    }

    // Check if the player has already used the Re-Roll ability
    if (gameState.getCurrentTurnPlayer().hasUsedAbility(AbilityTypes::Reroll)) {
        cout << "You have already used the Re-Roll ability this turn." << endl;
        return;
    }

    // Check if the player has the Re-Roll ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Reroll)) {
        cout << "You do not have the Re-Roll ability." << endl;
        return;
    }

    // Empty the player's hand
    gameState.getCurrentTurnPlayer().clear();

    // Draw two new cards
    DeckCard& deck = gameState.getDeckCards();
    cout << "Drawing two new cards..." << endl;

    // Check if there is enough cards in the deck
    if (deck.countItems() < 2) {
        cout << "Not enough cards in the deck." << endl;
        return;
    }

    // Add the new cards to the player's hand
    gameState.getCurrentTurnPlayer().addItem(deck.drawCard());
    gameState.getCurrentTurnPlayer().addItem(deck.drawCard());

    cout << "Cards drawn" << endl;

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(AbilityTypes::Reroll, true);
}
