#include <iostream>

using namespace std;

class A {
public:
    int x;
    A() : x(0) {}

    void display() {
        cout << "A's x: " << x << endl;
    }
};

class B : public A {
public:
    int x;
    B() : x(1) {}

    void display() {
        cout << "B's x: " << x << endl;
    }
};

class C : public B {
public:
    int x;
    C() : x(2) {} 

    void display() {
        cout << "C's x: " << x << endl;
    }

    void setA_x(int value) {
        A::x = value;
    }
};

int main() {
    C c;
    c.display();
    c.B::display();
    c.A::display();

    c.setA_x(18);

    c.A::display();
    return 0;
}
