#include <iostream>
#include <cmath>
using namespace std;

// Define the function whose root we want to find
double f(double x) {
    // Example: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

// Secant Method implementation
void secant(double x0, double x1, double tol, int maxIter) {
    double x2;
    int iter = 0;

    cout << "Iter\tx0\t\tx1\t\tx2\t\tf(x2)\n";
    cout << "----------------------------------------------------------\n";

    while (iter < maxIter) {
        double f0 = f(x0);
        double f1 = f(x1);

        // Prevent division by zero
        if (fabs(f1 - f0) < 1e-12) {
            cout << "Division by zero error. The method fails." << endl;
            return;
        }

        // Compute the next approximation
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        cout << iter + 1 << "\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f(x2) << endl;

        // Check convergence
        if (fabs(f(x2)) < tol) {
            cout << "\nRoot found at x = " << x2 << " after " << iter + 1 << " iterations." << endl;
            return;
        }

        // Update points
        x0 = x1;
        x1 = x2;
        iter++;
    }

    cout << "\nThe method did not converge within " << maxIter << " iterations." << endl;
    cout << "Approximate root = " << x2 << endl;
}

int main() {
    double x0, x1, tol;
    int maxIter;

    cout << "Enter initial guesses x0 and x1: ";
    cin >> x0 >> x1;

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIter;

    secant(x0, x1, tol, maxIter);

    return 0;
}
