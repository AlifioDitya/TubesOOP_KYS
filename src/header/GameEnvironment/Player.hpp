// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "InventoryHolder.hpp"
#include "Card.hpp"
#include <vector>

using std::vector;

class Player: public InventoryHolder {
private:
    int playerID;
    vector<Card> hand;
public:
    // Default ctor
    Player();

    // Specified ctor
    Player(int);

    // cctor
    Player(const Player&);

    virtual int countItems() const override {
        return hand.size();
    }

    virtual void addItem() override {
        // Deal a new card to the player's hand
        hand.push_back(Card());
    }

    virtual void removeItem() override {
        // Discard the player's hand
        hand.clear();
    }

    // ...
};

#endif