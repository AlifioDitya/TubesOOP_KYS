#include "../Combination.hpp"

class FullHouse : public Combination {
   private:
    vector<Card> triple;
    pair<Card, Card> cardPair;

   public:
    FullHouse(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
