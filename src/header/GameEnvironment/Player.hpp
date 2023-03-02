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

class Player: public InventoryHolder {
private:
    int playerID;
    vector<Card> hand;
    int point;
    string name;
    bool hasPlayed;
    bool usedAbility;
    bool nerfed;

public:
    // Default ctor
    Player();

    // Specified ctor
    Player(int, vector<Card>, int, string, bool);

    // cctor
    Player(const Player&);

    // operator=
    Player& operator=(const Player&);

    // Virtual overrides
    // Returns the number of items in the inventory
    virtual int countItems() const;

    // Adds an item to the inventory
    virtual void addItem(Card);

    // Removes an item from the inventory
    virtual void clear();

    // ========== Getters ==========
    // Return player id
    int getId() const;
    
    // Return player points
    int getPoint() const;

    // Return player name
    string getName() const;

    // Return player hand
    vector<Card> getHand() const;

    // ========== Setters ==========
    // Set player hand on index
    void setHand(int, Card);

    // Set player hand as vector
    void setHand(vector<Card>);

    // Set ability used
    bool setAbilityUsed(AbilityTypes, bool);

    // Set abilityless
    bool setNerfed(bool);

    // ========== Predicates ==========
    // Check if player has ability
    bool hasAbility(AbilityTypes);
    
    // Check if player has used an ability
    bool hasUsedAbility();
    
    bool hasUsedAbility(AbilityTypes);

    // Check if player has played this round
    bool hasPlayedThisRound();

    // Check if the player has been applied Abilityless by other player
    bool isNerfed();

    // ========= Others ==========
    // Switching cards with other player
    // Switch hands
    void switchCards(Player&);

    // Switch specific cards
    void switchCards(int, int, Player&);

    // Print hand
    void printHand();

    // ...
};

#endif