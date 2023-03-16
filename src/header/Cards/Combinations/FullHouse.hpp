#include "../Combination.hpp"

/**
 * @class FullHouse
 * @brief Class that defines the Full House combination
 * @extends Combination
 *
 */
class FullHouse : public Combination {
   private:
    /**
     * @brief Construct a new FullHouse object
     */
    FullHouse(const vector<Card>& combinationCards);

   public:
    /**
     * @brief Method to get combination type in string representation
     * @return Combination type in string representation
     */
    string getComboTypeString() const override;

    /**
     * @brief Calculate a new Full House combination value
     * @return Value of combination
     */
    long double getValue() const override;

    /**
     * @brief Generate permutation of Full House from given cards, combination will contain at least
     * one hand card
     * @param tableCards List of 5 community/table cards
     * @param tableCards List of 2 hand cards
     * @return Polymorphic Combination pointer of type FullHouse
     */
    static Combination* getFullHouse(const vector<Card>& tableCards, const vector<Card>& handCards);
};
