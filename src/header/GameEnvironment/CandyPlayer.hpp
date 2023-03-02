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

public:
    // Default ctor
    CandyPlayer();

    // Specified ctor
    CandyPlayer(int, vector<Card>, int, string, bool);

    // cctor
    CandyPlayer(const Player&);

    // operator=
    CandyPlayer& operator=(const Player&);


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

    // Check if the player has been applied Abilityless by other player
    bool isNerfed();

    // ========= Others ==========
    // Switching cards with other player
    // Switch hands
    void switchCards(Player&);

    // Switch specific cards
    void switchCards(int, int, Player&);

    // ...
};

#endif