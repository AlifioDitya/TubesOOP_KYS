// GameState.hpp
#ifndef CANDYGAMESTATE_HPP
#define CANDYGAMESTATE_HPP

#include "CandyPlayer.hpp"
#include "GameState.hpp"
#include "DeckCard.hpp"
#include "TableCard.hpp"
#include <vector>

using std::vector;

class CandyGameState: public GameState<CandyPlayer> {
private:
    
public:
    // Default ctor
    CandyGameState();

    // Specified ctor
    CandyGameState(vector<CandyPlayer>, int, int, int, TableCard, DeckCard);

    // cctor
    CandyGameState(const CandyGameState&);

    // dtor
    ~CandyGameState();

    // Predicates
    bool hasAllUsedAbility();
};

#endif