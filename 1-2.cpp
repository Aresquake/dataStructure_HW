#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

class quadraticEq {
private:
    double a, b, c;

public:
    quadraticEq(double a = 1, double b = 0, double c = 0) : a(a), b(b), c(c) {}

    quadraticEq operator+(const quadraticEq& other) const {
        return quadraticEq(a + other.a, b + other.b, c + other.c);
    }

    quadraticEq operator-(const quadraticEq& other) const {
        return quadraticEq(a - other.a, b - other.b, c - other.c);
    }

    bool operator==(const quadraticEq& other) const {
        return (a == other.a && b == other.b && c == other.c);
    }

    bool operator!=(const quadraticEq& other) const {
        return !(*this == other);
    }

    friend istream& operator>>(istream& in, quadraticEq& eq) {
        cout << "Enter coefficients a, b, c: ";
        in >> eq.a >> eq.b >> eq.c;
        return in;
    }

    friend ostream& operator<<(ostream& out, const quadraticEq& eq) {
        out << eq.a << "x^2 + ";
        if(eq.b < 0)
          out << "(" << eq.b << ")" << "x + ";
        else
          out << eq.b << "x + ";
        if(eq.c < 0)
          out << "(" << eq.c << ")";
        else
          out << eq.c;
        return out;
    }

   
    void findRoots() const {
        double D = b * b - 4 * a * c;
        if (D > 0) {
            // Two real roots
            double root1 = (-b + sqrt(D)) / (2 * a);
            double root2 = (-b - sqrt(D)) / (2 * a);
            cout << "The equation has two real roots: " << root1 << " and " << root2 << "\n";
        } else if (D == 0) {
            // One real root (repeated)
            double root = -b / (2 * a);
            cout << "The equation has one repeated root: " << root << "\n";
        } 
        else
        {
            // Two complex roots
            complex<double> root1 = complex<double>(-b, sqrt(-D)) / (2.0 * a);
            complex<double> root2 = complex<double>(-b, -sqrt(-D)) / (2.0 * a);
  
            cout << "The equation has two complex roots: " << root1.real() << "+";
            if(root1.imag() < 0)
              cout << "(" << root1.imag() << ")" << "i";
            else
              cout << root1.imag() << "i";
          
            cout << " and " << root2.real() << "+";
            if(root2.imag() < 0)
              cout << "(" << root2.imag() << ")" << "i";
            else
              cout << root2.imag() << "i" << "\n";
        }
    }
};


int main() {
    quadraticEq eq1, eq2;

    cin >> eq1 >> eq2;
    cout << "Equation 1: " << eq1 << "\n";
    cout << "Equation 2: " << eq2 << "\n";

    quadraticEq sum = eq1 + eq2;
    quadraticEq diff = eq1 - eq2;

    cout << "Sum of equations: " << sum << "\n";
    cout << "Difference of equations: " << diff << "\n";


    if (eq1 == eq2)
        cout << "The equations are equal.\n";
    else
        cout << "The equations are not equal.\n";

    cout << "Roots of equation 1:\n";
    eq1.findRoots();
    cout << "Roots of equation 2:\n";
    eq2.findRoots();

    return 0;
}

