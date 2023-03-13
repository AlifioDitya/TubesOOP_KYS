#include "../../header/GameEnvironment/AbilityDeckCard.hpp"
#include "../../header/GameEnvironment/DeckCard.hpp"
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
    srand(time(NULL));
    random_shuffle(temp.begin(), temp.end());
    deck = stack<AbilityTypes>(temp);
    
}
