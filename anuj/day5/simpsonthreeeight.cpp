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
    int n;       // Number of subintervals (must be multiple of 3)

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (multiple of 3, n): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Error: Number of subintervals must be a multiple of 3 for Simpson's 3/8 Rule.\n";
        return 1;
    }

    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b);

    // Apply Simpson's 3/8 formula
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 3 * f(a + i * h);
    }

    double integral = sum * 3 * h / 8.0;

    cout << "\nApproximate value of the integral using Simpson's 3/8 Rule: "
         << integral << endl;

    return 0;
}
