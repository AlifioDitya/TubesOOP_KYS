// Player.hpp
#ifndef CANDYPLAYER_HPP
#define CANDYPLAYER_HPP

#include "Player.hpp"
#include "../Cards/Card.hpp"
#include "../../enums/AbilityTypes.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

class CandyPlayer: public Player {
private:
    bool usedAbility;
    bool nerfed;
    uint64_t point;
    AbilityTypes ability;

public:
    // Default ctor
    CandyPlayer();

    // Specified ctor
    CandyPlayer(int id, const vector<Card>& hand, uint64_t point, string name, bool hasPlayed);

    // cctor
    CandyPlayer(const CandyPlayer&);

    // ========== Operators ==========

    CandyPlayer& operator=(const CandyPlayer&);
    bool operator<(const CandyPlayer& other);
    bool operator>(const CandyPlayer& other);

    // ========== Setters ==========

    // Set ability used
    void setAbilityUsed(bool);

    // Set abilityless
    void setNerfed(bool);

    // Set ability
    void setAbility(AbilityTypes);

    // ========== Predicates/Getters ==========

    // get ability
    AbilityTypes getAbility();

    // Check if player has ability
    bool hasAbility(AbilityTypes) const;
    
    // Check if player has used an ability
    bool hasUsedAbility() const;

    // Check if the player has been applied Abilityless by other player
    bool isNerfed() const;

    // Return player points
    uint64_t getPoint() const;

    // interface for getPoint()
    uint64_t getValue() const;

    // ========= Other Methods ==========

    // add point
    void addPoint(uint64_t);
    
    // Switching hands with other player
    void switchCards(CandyPlayer&);

    // Switch specific cards
    void switchCards(int idx1, int idx2, CandyPlayer& other);

    // ...
};

#endif