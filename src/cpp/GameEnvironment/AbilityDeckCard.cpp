// AbilityDeckCard.cpp
#include "../../header/GameEnvironment/AbilityDeckCard.hpp"
#include "../../header/GameEnvironment/DeckCard.hpp"

#include <algorithm>
#include <deque>
#include <iostream>

using std::random_shuffle;
using std::deque;

AbilityDeckCard::AbilityDeckCard() {
    defaultConfig();
}

AbilityDeckCard::AbilityDeckCard(const vector <AbilityTypes>& cards) : DeckCard<AbilityTypes>(cards) {}

// ========== Methods ==========

void AbilityDeckCard::defaultConfig() {
    // INISIASI 

    deque<AbilityTypes> temp {Reverse, Switch, Reroll, SwapCard, Quadruple, Quarter, Abilityless};
    srand(time(NULL));
    random_shuffle(temp.begin(), temp.end());
    clear();
    deck = stack<AbilityTypes>(temp);
}