/**
 * @file TableCard.hpp
 * @brief Header file of the TableCard class that defines the Cards on the table.
 */
#ifndef TABLE_CARD_HPP
#define TABLE_CARD_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"
#include <vector>

using std::vector;

/**
 * @class TableCard
 * @brief Class that defines the cards on the table
 * @extends InventoryHolder
 * 
 */
class TableCard : public InventoryHolder<Card> {
private:
    /**
     * @brief Vector of cards on the table
     * 
     */
    std::vector<Card> cards;

public:
    /**
     * @brief Returns the number of items in the inventory.
     * 
     * @return the Number of items in the inventory 
     */
    virtual int countItems() const;

    /**
     * @brief Get all of the cards on the table that is relevant to the current game state
     * 
     * @return a vector of cards on the table 
     */
    vector<Card> getCards();

    /**
     * @brief Adds an item to the inventory
     * 
     */
    virtual void addItem(const Card&);

    /**
     * @brief Removes all of the items in the inventory
     * 
     */
    virtual void clear();

    /**
     * @brief Set the table cards
     * 
     * @param cards List of cards representing table cards to be set
     */
    void setCards(const vector<Card>& cards);

    /**
     * @brief Shows all of the table cards
     * 
     */
    void showCards();
};

#endif