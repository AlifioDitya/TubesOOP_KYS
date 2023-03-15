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

vector<vector<Card>> Solver::getPermutations(int l, int r) {
    // Permutations saved in a vector of vectors
    vector<vector<Card>> permutations;

    // Base case: Last element of vector reached, save permutated cards
    if (l == r) {
        if (find(permutations.begin(), permutations.end(), cards) != permutations.end()) {
            permutations.push_back(cards);
        }
    } else {
    // Recursion: Permute sub sections of cards
        for (int i = l; i <= r; i++) {
            swap(cards[l], cards[i]);
            auto subPerm = getPermutations(l + 1, r);

            for (int j = 0; j < subPerm.size(); j++) {
                permutations.push_back(subPerm[j]);
            }

            swap(cards[l], cards[i]);
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
    } else if (op == '/') {
        // Note: Zero division of doubles results in `inf`
        return num1 / num2;
    }

    return num1;
}

void Solver::calculateSolutions(vector<Card>) {
    string equation;

    vector<char> ops = {'+', '-', '*', '/'};

    // Iterate through all permutation of operations
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                // Parentheses style 1: ((num1 op1 num2) op2 num3) op3 num 4
                if (fabs(evaluateExpr(evaluateExpr(evaluateExpr((double) cards[0].getRank(), ops[i], (double) cards[1].getRank()), ops[j], (double) cards[2].getRank()), ops[k], (double) cards[3].getValue()) - 24.0) < 1e-8) {
                    equation = "((" + to_string(cards[0].getRank()) + " " + ops[i] + " " + to_string(cards[1].getRank()) + ") " + ops[j] + " " + to_string(cards[2].getRank()) + ") " + ops[k] + " " + to_string(cards[3].getValue());
                    solutions.push_back(equation);
                }

                // Parentheses style 2: (num1 op1 (num2 op2 num3)) op3 num4
                if (fabs(evaluateExpr(evaluateExpr((double) cards[0].getRank(), ops[i], evaluateExpr((double) cards[1].getRank(), ops[j], (double) cards[2].getRank())), ops[k], (double) cards[3].getValue()) - 24.0) < 1e-8) {
                    equation = "(" + to_string(cards[0].getRank()) + " " + ops[i] + " " + "(" + to_string(cards[2].getRank()) + " " + ops[j] + " " + to_string(cards[3].getValue()) + "))" + " " + ops[k] + " " + to_string(cards[3].getValue());
                    solutions.push_back(equation);
                }

                // Parentheses style 3: (num1 op1 num2) op2 (num3 op3 num4)
                if (fabs(evaluateExpr(evaluateExpr((double) cards[0].getRank(), ops[i], (double) cards[1].getRank()), ops[j], evaluateExpr((double) cards[2].getRank(), ops[k], (double) cards[3].getValue())) - 24.0) < 1e-8) {
                    equation = "(" + to_string(cards[0].getRank()) + " " + ops[i] + " " + to_string(cards[1].getRank()) + ") " + ops[j] + " (" + to_string(cards[2].getRank()) + " " + ops[k] + " " + to_string(cards[3].getValue()) + ")";
                    solutions.push_back(equation);
                }

                // Parentheses style 4: num1 op1 ((num2 op2 num3) op3 num4)
                if (fabs(evaluateExpr((double) cards[0].getRank(), ops[i], evaluateExpr(evaluateExpr((double) cards[1].getRank(), ops[j], (double) cards[2].getRank()), ops[k], (double) cards[3].getValue())) - 24.0) < 1e-8) {
                    equation = to_string(cards[0].getRank()) + " " + ops[i] + " ((" + to_string(cards[1].getRank()) + " " + ops[j] + " " + to_string(cards[2].getRank()) + ") " + ops[k] + " " + to_string((int) + (double) cards[3].getValue()) + ")";
                    solutions.push_back(equation);
                }

                // Parentheses style 5: num1 op1 (num2 op2 (num3 op3 num4))
                if (fabs(evaluateExpr((double) cards[0].getRank(), ops[i], evaluateExpr((double) cards[1].getRank(), ops[j], evaluateExpr((double) cards[2].getRank(), ops[k], (double) cards[3].getValue()))) - 24.0) < 1e-8) {
                    equation = to_string(cards[0].getRank()) + " " + ops[i] + " (" + to_string(cards[1].getRank()) + " " + ops[j] + " (" + to_string(cards[2].getRank()) + " " + ops[k] + " " + to_string(cards[3].getValue()) + "))";
                    solutions.push_back(equation);
                }
            }
        }
    }
}

void Solver::solve24() {
    vector<vector<Card>> permCards = getPermutations(0, cards.size()-1);

    // Sequentially iterate through a set of permutated cards
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
        for (int i = 0; i < solutions.size(); i++) {
            cout << (i+1) << ". " << solutions[i] << endl;
        }
        cout << endl << solutions.size() << " solusi unik ditemukan.\n" << endl;    
    } else {
        // No solutions
        cout << "Tidak ada solusi yang ditemukan.\n" << endl;
    }
}