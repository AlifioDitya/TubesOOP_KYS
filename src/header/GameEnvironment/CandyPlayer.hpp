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
    AbilityTypes ability;

public:
    // Default ctor
    CandyPlayer();

    // Specified ctor
    CandyPlayer(int id, const vector<Card>& hand, unsigned long long point, string name, bool hasPlayed);

    // cctor
    CandyPlayer(const CandyPlayer&);

    // operator=
    CandyPlayer& operator=(const CandyPlayer&);

    // get ability
    AbilityTypes getAbility();
    // Set ability used
    void setAbilityUsed(bool);

    // Set abilityless
    void setNerfed(bool);

    // Set ability
    void setAbility(AbilityTypes);

    // ========== Predicates ==========
    // Check if player has ability
    bool hasAbility(AbilityTypes) const;
    
    // Check if player has used an ability
    bool hasUsedAbility() const;

    // Check if the player has been applied Abilityless by other player
    bool isNerfed() const;

    // ========= Others ==========
    // Switching cards with other player
    // Switch hands
    void switchCards(CandyPlayer&);

    // Switch specific cards
    void switchCards(int idx1, int idx2, CandyPlayer& other);

    unsigned long long getValue() const;

    // ...
};

#endif