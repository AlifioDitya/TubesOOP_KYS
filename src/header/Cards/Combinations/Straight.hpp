#include "../Combination.hpp"

class Straight : public Combination {
   private:
    Straight(const vector<Card> tableCards, const vector<Card> handCards,
             const vector<Card> bestCombination);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getStraight(const vector<Card> tableCards, const vector<Card> handCards);
};
