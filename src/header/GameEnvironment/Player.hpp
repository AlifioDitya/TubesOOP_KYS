// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"
#include <vector>


class Player: public InventoryHolder {
private:
    const int playerID;
    std::vector<Card> hand;

public:

    // Specified ctor
    Player(int);

    // cctor
    Player(const Player&);

    // Return player id
    int getId() const;

     // Returns the number of items in the inventory
    virtual int countItems() const;

    // Adds an item to the inventory
    virtual void addItem(Card);

    // Removes an item from the inventory
    virtual void clear();

    // ...
};

#endif