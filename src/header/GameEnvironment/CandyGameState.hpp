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
    DeckCard<AbilityTypes> abilities;
public:
    // Default ctor
    CandyGameState();

    // Specified ctor
    CandyGameState(vector<CandyPlayer>, int, int, int, TableCard, DeckCard<Card>, DeckCard<AbilityTypes>);

    // cctor
    CandyGameState(const CandyGameState&);

    // dtor
    ~CandyGameState();

    // Predicates

    // check if all player used ability
    bool hasAllUsedAbility() const;

    void setAbilities(DeckCard<AbilityTypes>);
    
    DeckCard<AbilityTypes>& getAbilities();

    static const long long initialPoint;
    static const long long winnerPoint;
};

#endif