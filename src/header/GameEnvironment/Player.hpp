// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"
#include "../../enums/AbilityTypes.hpp"
#include <vector>

using std::vector;

class Player: public InventoryHolder {
private:
    const int playerID;
    vector<Card> hand;
    int point;

public:

    // Specified ctor
    Player(int);

    // cctor
    Player(const Player&);

    // Return player id
    int getId() const;

    // Return player hand
    vector<Card> getHand() const;

    // Return player points
    int getPoint() const;

     // Returns the number of items in the inventory
    virtual int countItems() const;

    // Adds an item to the inventory
    virtual void addItem(Card);

    // Removes an item from the inventory
    virtual void clear();

    // Set ability used
    bool setAbilityUsed(AbilityTypes, bool);

    // Check if player has ability
    bool hasAbility(AbilityTypes);
    
    // Check if player has used an ability
    bool hasUsedAbility(AbilityTypes);

    // ...
};

#endif