/**
 * @file Player.hpp
 * @brief Header file for the Player class that defines the in-game player.
 * 
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "InventoryHolder.hpp"
#include "../Cards/Card.hpp"
#include "../../enums/AbilityTypes.hpp"
#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;
using std::set;

/**
 * @class Player
 * @brief Class that defines the in-game player
 * @extends InventoryHolder
 * 
 */
class Player : public InventoryHolder<Card> {
protected:
    /**
     * @brief Id of the player
     * 
     */
    int playerID;

    /**
     * @brief Hand cards of the player
     * 
     */
    vector<Card> hand;

    /**
     * @brief Player's username
     * 
     */
    string name;

    /**
     * @brief Status of a player's turn in the round of a game
     * 
     */
    bool hasPlayed;

public:
    /**
     * @brief Construct a new Player object
     * 
     */
    Player();

    /**
     * @brief Construct a new Player object with specified parameters
     * 
     * @param id Id of a player
     * @param hand List of cards containing player's hand
     * @param name Player's username
     * @param hasPlayed Player's turn status in a round of a game 
     */
    Player(int id, const vector<Card>& hand, string name, bool hasPlayed);

    /**
     * @brief Destroy the Player object
     * 
     */
    ~Player();

    /**
     * @brief Copy constructs a new Player object
     * @param copyPlayer Player to be copied.
     */
    Player(const Player&);

    /**
     * @brief Assignment operator for the player class
     * 
     * @return Player reference to be assigned
     */
    Player& operator=(const Player&);
    // bool operator<(const Player&);
    // bool operator>(const Player& other);

    /**
     * @brief Get the player Id
     * 
     * @return Player's Id
     */
    int getId() const;

    /**
     * @brief Get the player's username
     * 
     * @return Player's username
     */
    string getName() const;

    /**
     * @brief Get the Player's hand card
     * 
     * @return a vector of cards of the player's hand
     */
    vector<Card> getHand() const;

    /**
     * @brief Returns the number of items in the inventory.
     * 
     * @return the Number of items in the inventory 
     */
    virtual int countItems() const;

    /**
     * @brief Set one of the Hand cards in a specified index of a player
     * @param Idx The card's index in the player's hand cards
     * @param Card The card to be set
     */
    void setHand(int, Card);

    /**
     * @brief Set the entire Hand cards of the Player
     * @param cards Vector of cards to be set as hand cards
     */
    void setHand(vector<Card>);

    /**
     * @brief Set the status of the player's current playing in a round
     * 
     */
    void setHasPlayed(bool);

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
     * @brief Removes the item from a hand in a specified index.
     * 
     * @param idx Index of item to be removed
     * @return Item that is removed
     */
    Card PutCard(int idx);

    /**
     * @brief Prints the current hand of the player
     * 
     */
    void printHand();

    /**
     * @brief a Predicate to check if the player has played the current round
     * 
     * @return true if the player has played the current round.
     * @return false otherwise.
     */
    bool hasPlayedThisRound() const;

    // ========== Easter egg methods ===========

    void generateRandomHand(int amount);

    void inputHand(int amount);
};

#endif