#include "../Combination.hpp"

/**
 * @class TwoPair
 * @brief Class that defines the Two Pair combination
 * @extends Combination
 *
 */
class TwoPair : public Combination {
   private:
    /**
     * @brief Construct a new TwoPair object
     */
    TwoPair(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Two Pair combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Two Pair from given cards, combination will contain at least
     * one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type TwoPair
     */
    static Combination* getTwoPair(const vector<Card>& tableCards, const vector<Card>& handCards);
};
