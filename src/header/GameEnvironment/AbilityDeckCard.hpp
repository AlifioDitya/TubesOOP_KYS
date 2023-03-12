
// AbilityDeckCard.hpp
#ifndef ABILITYDECKCARD_HPP
#define ABILITYDECKCARD_HPP

#include "DeckCard.hpp"

class AbilityDeckCard:public DeckCard<AbilityTypes> {
    private:
    
    public:
    void defaultConfig();

};

#endif