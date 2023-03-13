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
    int reversePlayerId;

public:
    // Default ctor
    CandyGameState();

    // Specified ctor
    CandyGameState(const vector<CandyPlayer>& playerList, int roundNum, uint64_t points, const TableCard& tableCard, 
        const GameDeckCard& deckCard, const AbilityDeckCard& abilities, int reversePlayerId);

    // cctor
    CandyGameState(const CandyGameState&);

    // dtor
    ~CandyGameState();

    // Predicates
    int getReversePlayerId() const;

    // check if all player used ability
    bool hasAllUsedAbility() const;

    void setAbilities(const AbilityDeckCard&);

    void setNextTurn();

    void setReversePlayerId(int);
    
    AbilityDeckCard& getAbilities();

    static const uint64_t initialPoint;
    static const uint64_t winnerPoint;
};

#endif