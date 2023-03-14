#include "../Combination.hpp"

class TwoPair : public Combination {
   private:
    pair<Card, Card> highPair;
    pair<Card, Card> lowPair;
    Card kicker;

   public:
    TwoPair(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
    static Combination* getTwoPair(const vector<Card> tableCards, const vector<Card> handCards);
};
