#include <utility>

#include "../Combination.hpp"

/**
 * @class Pair
 * @brief Class that defines the Pair combination
 * @extends Combination
 *
 */
class Pair : public Combination {
   private:
    /**
     * @brief Construct a new Pair object
     */
    Pair(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Pair combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Pair from given cards, combination will contain at least
     * one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type Pair
     */
    static Combination* getPair(const vector<Card>& tableCards, const vector<Card>& handCards);
};
