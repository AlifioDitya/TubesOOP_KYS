
// AbilityDeckCard.hpp
#ifndef ABILITYDECKCARD_HPP
#define ABILITYDECKCARD_HPP

#include "DeckCard.hpp"
#include "../../enums/AbilityTypes.hpp"

class AbilityDeckCard:public DeckCard<AbilityTypes> {
    private:
    
    public:
    AbilityDeckCard();
    AbilityDeckCard(const vector<AbilityTypes>&);
    void defaultConfig();

};

#endif