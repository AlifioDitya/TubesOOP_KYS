// Abilityless.hpp
#ifndef PLAYERINVOLVEDABILITY_HPP
#define PLAYERINVOLVEDABILITY_HPP

#include "Ability.hpp"

class PlayerInvolvedAbility : public Ability {

protected:

    // ========== Protected Methods ==========

    // return player index that is chosen
    int selectPlayer(CandyGameState& gameState, const vector<CandyPlayer>& playerList, string label);

public:


};

#endif