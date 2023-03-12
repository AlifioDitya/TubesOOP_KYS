#include "../../header/GameEnvironment/AbilityDeckCard.hpp"

#include "algorithm"
#include "deque"
using std::random_shuffle;
using std::deque;

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
