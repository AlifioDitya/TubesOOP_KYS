#include "../../header/GameEnvironment/AbilityDeckCard.hpp"

AbilityDeckCard::AbilityDeckCard() {
    defaultConfig();
}

AbilityDeckCard::AbilityDeckCard(const vector<AbilityTypes>& cards): DeckCard<AbilityTypes>(cards) {
}

void AbilityDeckCard::defaultConfig() {
    // INISIASI 

    deque<AbilityTypes> temp {Reroll, Quadruple, Quarter, Reverse, SwapCard, Switch, Abilityless};
    random_shuffle(temp.begin(), temp.end());
    deck = stack<AbilityTypes>(temp);
    
}