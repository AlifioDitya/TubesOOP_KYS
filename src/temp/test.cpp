#include <iostream>
#include "IO.cpp"

using namespace std;


int main() {
    IO a;

    while (true) {
        try {
            a.getInput(1, 3);

            cout << a.getChoice() << endl;
            cout << "nice\n";
        } catch (exception& err) {
            cout << err.what();
        }
    }
}