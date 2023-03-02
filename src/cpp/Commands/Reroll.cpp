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

// Execute method
bool Reroll::executeCommand(CandyGameState& gameState) {
    if (this->command != CmdTypes::Reroll) {
        cout << "Command tidak tepat." << endl;
        return false;
    }

    // Check if the player has already used the Re-Roll ability
    if (gameState.getCurrentTurnPlayer().hasUsedAbility(AbilityTypes::Reroll)) {
        cout << "Maaf, kamu sudah pernah menggunakan REROLL." << endl;
        return false;
    }

    // Check if the player has the Re-Roll ability
    if (!gameState.getCurrentTurnPlayer().hasAbility(AbilityTypes::Reroll)) {
        cout << "Maaf, kamu tidak punya kartu Ability REROLL." << endl;
        return false;
    }

    // Get the deck
    DeckCard& deck = gameState.getDeckCards();

    // Check if there is enough cards in the deck
    if (deck.countItems() < 2) {
        cout << "Maaf, deck tidak memiliki kartu yang cukup." << endl;
        return false;
    }

    // Empty the player's hand
    cout << "Melakukan pembuangan dua kartu yang dimiliki" << endl;
    gameState.getCurrentTurnPlayer().clear();

    // Draw two new cards
    cout << "Kamu mendapatkan dua kartu baru yaitu:" << endl;

    // Add the new cards to the player's hand
    Card card1 = deck.drawCard();
    Card card2 = deck.drawCard();

    gameState.getCurrentTurnPlayer().addItem(card1);
    gameState.getCurrentTurnPlayer().addItem(card2);

    cout << "1. " << card1.getRank() << " " << card1.getColorString() << endl;
    cout << "2. " << card2.getRank() << " " << card2.getColorString() << endl;

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(AbilityTypes::Reroll, true);
    
    return true;
}