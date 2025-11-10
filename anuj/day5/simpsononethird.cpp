#include <iostream>
#include <cmath>
using namespace std;

// Function to integrate
double f(double x) {
    // Example function: f(x) = x^2
    return x * x;
}

int main() {
    double a, b; // Integration limits
    int n;       // Number of subintervals (must be even)

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (even n): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error: Number of subintervals must be even for Simpson's 1/3 Rule.\n";
        return 1;
    }

    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b);

    // Apply Simpson's 1/3 formula
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }

    double integral = sum * h / 3.0;

    cout << "\nApproximate value of the integral using Simpson's 1/3 Rule: "
         << integral << endl;

    return 0;
}
