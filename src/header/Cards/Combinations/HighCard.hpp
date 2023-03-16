#include "../Combination.hpp"

/**
 * @class HighCard
 * @brief Class that defines the High Card combination
 * @extends Combination
 *
 */
class HighCard : public Combination {
   private:
    /**
     * @brief Construct a new HighCard object
     */
    HighCard(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new High Card combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of High Card from given cards, combination will contain at least
     * one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type HighCard
     */
    static Combination* getHighCard(const vector<Card>& tableCards, const vector<Card>& handCards);
};
