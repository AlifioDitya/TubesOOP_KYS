#include "../Combination.hpp"

class HighCard : public Combination {
   private:
    HighCard(const vector<Card> tableCards, const vector<Card> handCards,
             const vector<Card> bestCombination);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getHighCard(const vector<Card> tableCards, const vector<Card> handCards);
};
