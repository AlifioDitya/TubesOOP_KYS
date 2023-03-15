#include "../../header/EasterEgg/Solver.hpp"
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::swap;
using std::to_string;
using std::fabs;
using std::string;
using std::find;

Solver::Solver() {
    this->cards = vector<Card>();
    this->solutions = vector<string>();
}

void Solver::setCards(vector<Card> cards) {
    this->cards = cards;
}

set<vector<Card>> Solver::getPermutations(int l, int r) {
    // Permutations saved in a set of vectors
    set<vector<Card>> permutations;

    // Base case: Last element of vector reached, save permutated cards
    if (l == r) {
        permutations.insert(this->cards);
    } else {
    // Recursion: Permute sub sections of cards
        for (int i = l; i <= r; i++) {
            swap(this->cards[l], this->cards[i]);
            auto subPerm = getPermutations(l + 1, r);
            permutations.insert(subPerm.begin(), subPerm.end());
            swap(this->cards[l], this->cards[i]);
        }
    }

    return permutations;
}

double Solver::evaluateExpr(double num1, char op, double num2) {
    // Evaluate operations
    if (op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == '*') {
        return num1 * num2;
    } else {
        // Note: Zero division of doubles results in `inf`
        return (double) num1 / (double) num2;
    }
}

void Solver::calculateSolutions(vector<Card> cardVec) {
    string equation;

    vector<char> ops = {'+', '-', '*', '/'};

    // Iterate through all permutation of operations
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                // Parentheses style 1: ((num1 op1 num2) op2 num3) op3 num 4
                if (fabs(evaluateExpr(evaluateExpr(evaluateExpr((double) cardVec[0].getRank(), ops[i], (double) cardVec[1].getRank()), ops[j], (double) cardVec[2].getRank()), ops[k], (double) cardVec[3].getRank()) - 24.0) < 1e-8) {
                    equation = "((" + to_string(cardVec[0].getRank()) + " " + ops[i] + " " + to_string(cardVec[1].getRank()) + ") " + ops[j] + " " + to_string(cardVec[2].getRank()) + ") " + ops[k] + " " + to_string(cardVec[3].getRank());
                    solutions.push_back(equation);
                }

                // Parentheses style 2: (num1 op1 (num2 op2 num3)) op3 num4
                if (fabs(evaluateExpr(evaluateExpr((double) cardVec[0].getRank(), ops[i], evaluateExpr((double) cardVec[1].getRank(), ops[j], (double) cardVec[2].getRank())), ops[k], (double) cardVec[3].getRank()) - 24.0) < 1e-8) {
                    equation = "(" + to_string(cardVec[0].getRank()) + " " + ops[i] + " " + "(" + to_string(cardVec[2].getRank()) + " " + ops[j] + " " + to_string(cardVec[3].getRank()) + "))" + " " + ops[k] + " " + to_string(cardVec[3].getRank());
                    solutions.push_back(equation);
                }

                // Parentheses style 3: (num1 op1 num2) op2 (num3 op3 num4)
                if (fabs(evaluateExpr(evaluateExpr((double) cardVec[0].getRank(), ops[i], (double) cardVec[1].getRank()), ops[j], evaluateExpr((double) cardVec[2].getRank(), ops[k], (double) cardVec[3].getRank())) - 24.0) < 1e-8) {
                    equation = "(" + to_string(cardVec[0].getRank()) + " " + ops[i] + " " + to_string(cardVec[1].getRank()) + ") " + ops[j] + " (" + to_string(cardVec[2].getRank()) + " " + ops[k] + " " + to_string(cardVec[3].getRank()) + ")";
                    solutions.push_back(equation);
                }

                // Parentheses style 4: num1 op1 ((num2 op2 num3) op3 num4)
                if (fabs(evaluateExpr((double) cardVec[0].getRank(), ops[i], evaluateExpr(evaluateExpr((double) cardVec[1].getRank(), ops[j], (double) cardVec[2].getRank()), ops[k], (double) cardVec[3].getRank())) - 24.0) < 1e-8) {
                    equation = to_string(cardVec[0].getRank()) + " " + ops[i] + " ((" + to_string(cardVec[1].getRank()) + " " + ops[j] + " " + to_string(cardVec[2].getRank()) + ") " + ops[k] + " " + to_string((int) + (double) cardVec[3].getRank()) + ")";
                    solutions.push_back(equation);
                }

                // Parentheses style 5: num1 op1 (num2 op2 (num3 op3 num4))
                if (fabs(evaluateExpr((double) cardVec[0].getRank(), ops[i], evaluateExpr((double) cardVec[1].getRank(), ops[j], evaluateExpr((double) cardVec[2].getRank(), ops[k], (double) cardVec[3].getRank()))) - 24.0) < 1e-8) {
                    equation = to_string(cardVec[0].getRank()) + " " + ops[i] + " (" + to_string(cardVec[1].getRank()) + " " + ops[j] + " (" + to_string(cardVec[2].getRank()) + " " + ops[k] + " " + to_string(cardVec[3].getRank()) + "))";
                    solutions.push_back(equation);
                }
            }
        }
    }

}

void Solver::solve24() {
    set<vector<Card>> permCards = getPermutations(0, cards.size()-1);

    for (auto it = permCards.begin(); it != permCards.end(); it++) {
        auto permVector = *it;
        calculateSolutions(permVector);
    }

    /* Solutions vector has been filled */
}

void Solver::printSolutions() {
    // Outputs solution vector
    if (solutions.size() != 0) {
        // Solutions found
        cout << "Solusi menghasilkan angka 24:" << endl;
        for (long unsigned int i = 0; i < solutions.size(); i++) {
            cout << (i+1) << ". " << solutions[i] << endl;
        }
        cout << endl << solutions.size() << " solusi unik ditemukan.\n" << endl;    
    } else {
        // No solutions
        cout << "Tidak ada solusi yang ditemukan.\n" << endl;
    }
}

void Solver::clearSolutions() {
    this->solutions.clear();
}