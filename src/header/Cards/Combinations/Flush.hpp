#include "../Combination.hpp"

/**
 * @class Flush
 * @brief Class that defines the Flush combination
 * @extends Combination
 *
 */
class Flush : public Combination {
   private:
    /**
     * @brief Construct a new Flush object
     */
    Flush(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Flush combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Flush from given cards, combination will contain at least
     * one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type Flush
     */
    static Combination* getFlush(const vector<Card>& tableCards, const vector<Card>& handCards);
};
