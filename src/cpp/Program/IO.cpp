#include "../../header/Program/IO.hpp"
#include "../../header/Exception/IOException.hpp"
#include <iostream>
#include "string"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

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
        } catch(const UnmatchedType& err) {
            cout << err.what() << " Masukan harus berupa angka." << endl;
        } catch(const exception& err) {
            cout << err.what() << endl;
            temp = -1;
        }
    }

    choice = temp;

}

void IO::newl() {
    cout << endl;
}
void IO::border() {
    cout << "==============================" << endl;
}