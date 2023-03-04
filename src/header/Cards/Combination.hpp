#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <vector>

#include "../../enums/CombinationTypes.hpp"
#include "Card.hpp"

using std::vector;

// KELAS SANGAT AMBIGU
// DO NO USE
// TP WAJIB DI SPEK
// SEMENTARA NYIMPEN KALKULASI KOMBINASI DULU
class Combination : public CardInterface {
   protected:
    // enum ComboMax = {};
    vector<Card> allCards;
    vector<Card> bestCombination;
    ComboTypes comboType;
    double weightedValue;

    vector<Card> findBestCombination(vector<Card>);
    ComboTypes findComboType(vector<Card>);
    double calculateWeightedValue(vector<Card>);

   public:
    // CTOR
    Combination(const vector<Card>);
    Combination(const Card[], int);

    ~Combination();

    vector<Card> getAllCards() const;
    vector<Card> getBestCombination() const;
    ComboTypes getComboType() const;
    double getWeightedValue() const;
};

#endif