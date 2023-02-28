using namespace std;

#include "../../header/GameEnvironment/Player.hpp"

 // Default ctor

// Specified ctor
Player::Player(int id): playerID(id) {

}

// cctor
Player::Player(const Player& other): playerID(other.playerID) {
    copy(other.hand.begin(), other.hand.end(), back_inserter(hand)); 
}

// Return player id
int Player::getId() const {
    return playerID;
}

// Returns the number of items in the inventory
int Player::countItems() const {
    return hand.size();
}

// Adds an item to the inventory
void Player::addItem(Card card) {
    hand.push_back(card);
}

// Removes an item from the inventory
void Player::clear() {
    hand.clear();
}

// ...