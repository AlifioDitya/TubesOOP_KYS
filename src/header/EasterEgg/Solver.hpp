#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "../Cards/Card.hpp"
#include "../GameEnvironment/Player.hpp"
#include <string>

using std::string;

class Solver {
private:
    vector<Card> cards;
    vector<string> solutions;
public:
    Solver();

    void setCards(vector<Card> cards);

    vector<vector<Card>> getPermutations(int l, int r);

    double evaluateExpr(double num1, char op, double num2);

    void calculateSolutions(vector<Card>);

    void solve24();

    void printSolutions();
};

#endif