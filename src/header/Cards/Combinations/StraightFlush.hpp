#include "../Combination.hpp"

class StraightFlush : public Combination {
   private:
    StraightFlush(const vector<Card> tableCards, const vector<Card> handCards,
                  const vector<Card> bestCombination);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getStraightFlush(const vector<Card> tableCards,
                                         const vector<Card> handCards);
};
