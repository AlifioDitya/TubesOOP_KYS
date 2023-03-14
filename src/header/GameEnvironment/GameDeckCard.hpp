/**
 * @file GameDeckCard.hpp
 * @brief Header file for the GameDeckCard class
 * 
 */
#ifndef GAMEDECKCARD_HPP
#define GAMEDECKCARD_HPP

#include "DeckCard.hpp"
#include "../Cards/Card.hpp"

/**
 * @class GameDeckCard
 * @brief Class for the Deck Card of a game
 * @extends DeckCard
 * 
 */
class GameDeckCard : public DeckCard<Card> {
public:
    /**
     * @brief Construct a new Game Deck Card object.
     * 
     */
    GameDeckCard();

    /**
     * @brief Copy constructs a new Game Deck Card object.
     */
    GameDeckCard(const vector<Card>&);

    /**
     * @brief Initiate the cards with a random configuration.
     * 
     */
    void defaultConfig();
};

#endif