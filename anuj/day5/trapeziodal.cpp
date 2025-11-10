#include <iostream>
#include <cmath>
using namespace std;

// Example function to integrate
double f(double x) {
    // You can change this function as needed
    return x * x; // f(x) = x^2
}

int main() {
    double a, b; // Limits of integration
    int n;       // Number of subintervals

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    double h = (b - a) / n; // Width of each trapezoid
    double sum = 0.5 * (f(a) + f(b)); // Start with first and last terms

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h); // Sum intermediate terms
    }

    double integral = sum * h;

    cout << "\nApproximate value of the integral using Trapezoidal Rule: " 
         << integral << endl;

    return 0;
}
