// Reroll.cpp
#include "../../header/Commands/Reroll.hpp"
#include "../../enums/CmdTypes.hpp"
#include "../../enums/AbilityTypes.hpp"
#include "../../header/Exception/CommandException.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// ctor
Reroll::Reroll() {
    this->command = CmdTypes::Ability;
    this->abilityType = AbilityTypes::Reroll;
}

// Execute method
void Reroll::executeCommand(CandyGameState& gameState) {

    validateAbility(gameState);
    
    // Get the deck
    DeckCard<Card>& deck = gameState.getDeckCards();

    vector<Card> newCards = deck.drawMany(2);

    // Empty the player's hand
    cout << "Melakukan pembuangan dua kartu yang dimiliki" << endl;
    gameState.getCurrentTurnPlayer().clear();

    // Draw two new cards
    cout << "Kamu mendapatkan dua kartu baru yaitu:" << endl;

    gameState.getCurrentTurnPlayer().setHand(newCards);

    cout << "1. " << newCards[0].getRank() << " " << newCards[0].getColorString() << endl;
    cout << "2. " << newCards[1].getRank() << " " << newCards[1].getColorString() << endl;

    // Set the ability used flag to true and end the turn
    gameState.getCurrentTurnPlayer().setAbilityUsed(true);

}