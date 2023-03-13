
// AbilityDeckCard.hpp
#ifndef ABILITYDECKCARD_HPP
#define ABILITYDECKCARD_HPP

#include "DeckCard.hpp"
#include "../../enums/AbilityTypes.hpp"

class AbilityDeckCard:public DeckCard<AbilityTypes> {
    private:
    
    public:

    // Ctor
    AbilityDeckCard();
    // Cctor
    AbilityDeckCard(const vector<AbilityTypes>&);

    // ========== Methods ==========

    // initiate deckcard with random configuration
    void defaultConfig();

};

#endif