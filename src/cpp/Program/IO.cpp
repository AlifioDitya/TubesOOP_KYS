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

// get integer input in range [lowerBound, upperBound]
void IO::getInput(int lowerBound, int upperBound) {
    int temp = -1;

    while (temp == -1) {
        try {

            string userInput;

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
        }

        catch(const UnmatchedType& err) {
            cout << err.what() << " Choice should be number." << endl;
        }

        catch(const exception& err) {
            cout << err.what() << endl;
            temp = -1;
        }
    }

    choice = temp;
}
bool IO::operator==(const int) {
    return choice == -1;
}

int IO::getChoice() const {
    return choice;
}