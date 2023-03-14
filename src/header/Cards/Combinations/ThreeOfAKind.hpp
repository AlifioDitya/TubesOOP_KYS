#include "../Combination.hpp"

class ThreeOfAKind : public Combination {
   private:
    ThreeOfAKind(const vector<Card> tableCards, const vector<Card> handCards,
                 const vector<Card> bestCombination);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getThreeOfAKind(const vector<Card> tableCards,
                                        const vector<Card> handCards);
};
