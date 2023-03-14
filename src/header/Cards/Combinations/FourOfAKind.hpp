#include "../Combination.hpp"

class FourOfAKind : public Combination {
   private:
    FourOfAKind(const vector<Card> tableCards, const vector<Card> handCards,
                const vector<Card> bestCombination);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getFourOfAKind(const vector<Card> tableCards, const vector<Card> handCards);
};
