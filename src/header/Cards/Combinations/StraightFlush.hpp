#include "../Combination.hpp"

class StraightFlush : public Combination {
   private:
    Card highCard;
    Color straightFlushColor;

   public:
    StraightFlush(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
