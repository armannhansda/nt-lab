#include <iostream>
#include <cmath>
using namespace std;

// Define the function for which we want to find the root
double f(double x) {
    // Example: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

// Bisection Method implementation
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c; // Midpoint
    int iteration = 0;

    cout << "Iter\ta\t\tb\t\tc\t\tf(c)\n";
    cout << "-----------------------------------------------------------\n";

    while ((b - a) >= tol) {
        c = (a + b) / 2; // Find the midpoint

        cout << iteration << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;

        // Check if midpoint is root
        if (fabs(f(c)) < tol) {
            break;
        }

        // Decide the side to repeat the steps
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iteration++;
    }

    cout << "\nThe root is approximately at x = " << c << endl;
}

int main() {
    double a, b, tol;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tol;

    bisection(a, b, tol);

    return 0;
}
