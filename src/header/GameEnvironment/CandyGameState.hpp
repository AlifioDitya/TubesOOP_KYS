// GameState.hpp
#ifndef CANDYGAMESTATE_HPP
#define CANDYGAMESTATE_HPP

#include "CandyPlayer.hpp"
#include "GameState.hpp"
#include "GameDeckCard.hpp"
#include "AbilityDeckCard.hpp"
#include <vector>

using std::vector;

class CandyGameState: public GameState<CandyPlayer> {
private:
    AbilityDeckCard abilities;
    bool isReversed;

public:
    // Default ctor
    CandyGameState();

    // Specified ctor
    CandyGameState(const vector<CandyPlayer>& playerList, int roundNum, int points, const TableCard& tableCard, 
        const GameDeckCard& deckCard, const AbilityDeckCard& abilities, bool isReversed);

    // cctor
    CandyGameState(const CandyGameState&);

    // dtor
    ~CandyGameState();

    // Predicates
    bool getIsReversed() const;

    // check if all player used ability
    bool hasAllUsedAbility() const;

    void setAbilities(const AbilityDeckCard&);

    void setNextTurn();

    void setIsReversed(bool);
    
    AbilityDeckCard& getAbilities();

    static const long long initialPoint;
    static const long long winnerPoint;
};

#endif