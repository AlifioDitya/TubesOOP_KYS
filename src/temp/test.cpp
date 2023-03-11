#include <iostream>
using namespace std;
enum c {
    Bruh=1
};

template <class T>
class a {

    public:
    T b;
};

int main() {
    a <c> d;    

    cout << d.b;

    return 0;
}

