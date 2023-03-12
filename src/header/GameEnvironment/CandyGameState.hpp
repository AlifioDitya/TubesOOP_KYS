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
    bool isReversed;

public:
    // Default ctor
    CandyGameState();

    // Specified ctor
    CandyGameState(const vector<CandyPlayer>& playerList, int roundNum, int points, const TableCard& tableCard, 
        const DeckCard<Card>& deckCard, const DeckCard<AbilityTypes>& abilities, bool isReversed);

    // cctor
    CandyGameState(const CandyGameState&);

    // dtor
    ~CandyGameState();

    // Predicates
    bool getIsReversed() const;

    // check if all player used ability
    bool hasAllUsedAbility() const;

    void setAbilities(const DeckCard<AbilityTypes>&);

    void setNextTurn();

    void setIsReversed(bool);
    
    DeckCard<AbilityTypes>& getAbilities();

    static const long long initialPoint;
    static const long long winnerPoint;
};

#endif