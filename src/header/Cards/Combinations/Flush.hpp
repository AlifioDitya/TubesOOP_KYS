#include "../Combination.hpp"

class Flush : public Combination {
   private:
    Color flushColor;

   public:
    Flush(const vector<Card> cards);
    string getComboTypeString() const override;
    double getValue() const override;
};
