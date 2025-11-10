#include <iostream>
#include <cmath>
using namespace std;

// Define the function f(x)
double f(double x) {
    // Example: f(x) = x^3 - x - 2
    return x*x*x - x - 2;
}

// Define the derivative f'(x)
double df(double x) {
    // Derivative of f(x): f'(x) = 3x^2 - 1
    return 3*x*x - 1;
}

// Newton-Raphson Method implementation
void newtonRaphson(double x0, double tol, int maxIter) {
    double x1;
    int iter = 0;

    cout << "Iter\tx0\t\tx1\t\tf(x1)\n";
    cout << "---------------------------------------------\n";

    while (iter < maxIter) {
        double f0 = f(x0);
        double df0 = df(x0);

        // Prevent division by zero
        if (fabs(df0) < 1e-12) {
            cout << "Derivative near zero. The method fails." << endl;
            return;
        }

        // Newton-Raphson formula
        x1 = x0 - f0 / df0;

        cout << iter + 1 << "\t" << x0 << "\t" << x1 << "\t" << f(x1) << endl;

        // Check convergence
        if (fabs(x1 - x0) < tol) {
            cout << "\nRoot found at x = " << x1 << " after " << iter + 1 << " iterations." << endl;
            return;
        }

        x0 = x1;
        iter++;
    }

    cout << "\nThe method did not converge within " << maxIter << " iterations." << endl;
    cout << "Approximate root = " << x1 << endl;
}

int main() {
    double x0, tol;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    newtonRaphson(x0, tol, maxIter);

    return 0;
}
