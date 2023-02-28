#include <stack>
#include <iostream>
using namespace std;
class B {

    public:
    ~B() {
        cout << "noo";
    }
};

class A {
    private:
    stack<B> l;
    public:

    A() {
        l.push(B());
    }

    void replace()
    {
        l = stack<B>();
    }
};


int main(){

    A a;

    a.replace();
    cout<< "end";

    return 0;
}