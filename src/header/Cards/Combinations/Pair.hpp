#include <utility>

#include "../Combination.hpp"

class Pair : public Combination {
   private:
    pair<Card, Card> pairCards;
    vector<Card> kickers;

   public:
    Pair(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
    static Combination* getPair(const vector<Card> tableCards, const vector<Card> handCards);
};
