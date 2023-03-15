#include "../Combination.hpp"

class TwoPair : public Combination {
   private:
    TwoPair(const vector<Card> tableCards, const vector<Card> handCards,
            const vector<Card> bestCombination);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getTwoPair(const vector<Card> tableCards, const vector<Card> handCards);
};
