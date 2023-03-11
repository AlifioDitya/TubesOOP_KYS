#include "../../header/Program/IO.hpp"
#include "../../header/Exception/IOException.hpp"
#include <iostream>

IO::IO() {
    choice = -1;
}

// get integer input in range [lowerBound, upperBound]
void IO::getChoice(int lowerBound, int upperBound) {
    int temp = NULL;

    while (temp == NULL) {
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
            temp = NULL;
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