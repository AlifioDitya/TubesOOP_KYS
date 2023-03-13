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
    uint64_t pointPool;

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

    // ========== Getters ==========

    // return player id that used reverse ability in this round
    int getReversePlayerId() const;

    // return pointPool
    uint64_t getPointPool() const ;

    // return abilities deck cards
    AbilityDeckCard& getAbilities();

    // ========== Predicates ==========

    // check if all player used ability in this round
    bool hasAllUsedAbility() const;

    // ========== Setters ==========

    // set abilities card deck
    void setAbilities(const AbilityDeckCard&);

    // move to next player turn
    void setNextTurn();

    // set player id that used reverse ability in this round
    void setReversePlayerId(int);

    // set pointpool value
    void setPointPool(uint64_t points);
    
    // ========== Other Methods ==========

    // print current leader board based on player point
    void printLeaderBoard() const;

    // print next round player order
    void printNextRoundTurn() const;

    // ========== Static Attributes ==========

    static const uint64_t initialPoint;
    static const uint64_t winnerPoint;
};

#endif