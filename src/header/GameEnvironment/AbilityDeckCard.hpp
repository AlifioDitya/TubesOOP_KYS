/**
*   @file AbilityDeckCard.hpp
*   @brief Header file for the AbilityDeckCard class.
**/

#ifndef ABILITYDECKCARD_HPP
#define ABILITYDECKCARD_HPP

#include "DeckCard.hpp"
#include "../../enums/AbilityTypes.hpp"

/**
*   @class AbilityDeckCard
*   @brief Class representing a deck card of ability types.
*   @extends DeckCard
**/
class AbilityDeckCard:public DeckCard<AbilityTypes> {
    private:
    
    public:

    /**
    *   @brief Constructor for AbilityDeckCard class
    **/
    AbilityDeckCard();
    
    /**
    *   @brief Constructor for AbilityDeckCard class with an input vector of ability types.
    *   @param[in] abilities vector of ability types to initialize the deck card.
    **/
    AbilityDeckCard(const vector<AbilityTypes>&);

    /**
    *   @brief Method to initialize the deck card with a random configuration of abilities.
    **/
    void defaultConfig();
};

#endif