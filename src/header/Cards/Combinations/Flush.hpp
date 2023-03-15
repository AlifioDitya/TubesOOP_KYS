#include "../Combination.hpp"

class Flush : public Combination {
   private:
    Flush(const vector<Card>& combinationCards);

   public:
    string getComboTypeString() const override;
    long double getValue() const override;
    static Combination* getFlush(const vector<Card>& tableCards, const vector<Card>& handCards);
};
