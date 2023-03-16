#include "../../header/Program/IO.hpp"
#include "../../header/Exception/IOException.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::stringstream;
using std::numeric_limits;
using std::streamsize;
using std::vector;

IO::IO() {
    choice = -1;
}

// ========== Operators ==========

bool IO::operator==(const int num) {
    return choice == num;
}

// ========== Getters ==========

int IO::getChoice() const {
    return choice;
}

// ========== Other Method ========== 

void IO::getInput(int lowerBound, int upperBound) {
    int temp = -1;

    while (temp == -1) {
        try {
            string userInput;

            cout << "Pilihan : ";
            cin >> userInput;

            for (auto c: userInput) {
                if (!isdigit(c)) {
                    throw UnmatchedType();
                }
            }

            temp = stoi(userInput);
            if (temp < lowerBound || temp > upperBound) {
                throw InvalidChoice();
            }
        } catch (const UnmatchedType& err) {
            cout << err.what() << " Masukan harus berupa angka." << endl;
        } catch (const exception& err) {
            cout << err.what() << endl;
            temp = -1;
        }
    }

    choice = temp;
}

vector<int> IO::inputCardStream(int n) {
    string input;
    vector<int> output = {};
    string token;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    stringstream ss(input);

    // Process input stream as tokenized strings separated by spaces
    while (ss >> token) {
        if (token == "A") {
            output.push_back(1);
        } else if (token == "J") {
            output.push_back(11);
        } else if (token == "Q") {
            output.push_back(12);
        } else if (token == "K") {
            output.push_back(13);
        } else {
            int value = 0;
            for (char c : token) {
                if (c < '0' || c > '9') {
                    // Invalid character involved
                    cout << "Input tidak tepat! hanya angka 2-10 atau J, Q, K, A diperbolehkan.\n" << endl;
                    return vector<int>();
                } else {
                    value = value * 10 + (c - '0');
                }
            }

            if (value < 2 || value > 10) {
                // Invalid character/number involved
                cout << "Input tidak tepat! hanya angka 2-10 atau J, Q, K, A diperbolehkan.\n" << endl;
                return vector<int>();
            } else {
                output.push_back(value);
            }

        }

    }

    try {
        if (output.size() != (long unsigned int) n) {
            // Invalid input format
            throw UnmatchedStream();
        }
    } catch (const UnmatchedStream& err) {
        cout << err.what() << " Mohon masukkan angka sebanyak " << n << " buah terpisah oleh spasi.";
    }

    return output;
}

void IO::newl() {
    cout << endl;
}

void IO::border() {
    cout << "==============================" << endl;
}