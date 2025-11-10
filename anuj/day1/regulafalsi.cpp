#include <iostream>
#include <cmath>
using namespace std;

// Define the function whose root we want to find
double f(double x) {
    // Example function: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

// Regula Falsi (False Position) Method implementation
void regulaFalsi(double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c = a; // Initial approximation
    cout << "Iter\ta\t\tb\t\tc\t\tf(c)\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 1; i <= maxIter; i++) {
        // Compute the point of intersection with the x-axis
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << endl;

        // Check for convergence
        if (fabs(f(c)) < tol) {
            cout << "\nRoot found at x = " << c << " after " << i << " iterations." << endl;
            return;
        }

        // Update the interval
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nThe method did not converge within " << maxIter << " iterations." << endl;
    cout << "Approximate root = " << c << endl;
}

int main() {
    double a, b, tol;
    int maxIter;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    regulaFalsi(a, b, tol, maxIter);

    return 0;
}
