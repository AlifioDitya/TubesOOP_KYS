// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"
#include "../../enums/AbilityTypes.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Player: public InventoryHolder<Card> {
protected:
    int playerID;
    vector<Card> hand;
    string name;
    bool hasPlayed;

public:
    // Default ctor
    Player();

    // Specified ctor
    Player(int id, const vector<Card>& hand, string name, bool hasPlayed);

    // dtor
    ~Player();

    // cctor
    Player(const Player&);

    // ========== Operators ==========

    Player& operator=(const Player&);
    // bool operator<(const Player&);
    // bool operator>(const Player& other);


    // ========== Getters ==========

    // Return player id
    int getId() const;

    // Return player name
    string getName() const;

    // Return player hand
    vector<Card> getHand() const;

    // Returns the number of items in the inventory
    virtual int countItems() const;

    // ========== Setters/Other Methods ==========

    // Set player hand on index
    void setHand(int, Card);

    // Set player hand as vector
    void setHand(vector<Card>);

    // Set hasPlayed
    void setHasPlayed(bool);

    // Adds an item to the inventory
    virtual void addItem(const Card&);

    // Removes all item from the inventory
    virtual void clear();

    // remove 1 item from hand
    Card PutCard(int idx);

    // Print hand
    void printHand();

    // ========== Predicates ==========

    // Check if player has played this round
    bool hasPlayedThisRound() const;

    // ...
};

#endif