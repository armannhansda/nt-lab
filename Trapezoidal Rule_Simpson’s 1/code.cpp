/*
Absolutely! Here's a complete C++ implementation for solving the integral

∫
0
1
1
1
+
𝑥
2
 
𝑑
𝑥
using the Trapezoidal Rule, Simpson’s 1/3 Rule, and Simpson’s 3/8 Rule, along with absolute error calculations compared to the exact value 
𝜋
4
.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

double exactIntegral() {
    return atan(1.0); // pi/4
}

double trapezoidalRule(int n) {
    double a = 0.0, b = 1.0;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += 2.0 * f(x);
    }

    return (h / 2.0) * sum;
}

double simpsonsOneThird(int n) {
    if (n % 2 != 0) {
        cout << "Simpson's 1/3 rule requires even n.\n";
        return 0.0;
    }

    double a = 0.0, b = 1.0;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2.0 : 4.0) * f(x);
    }

    return (h / 3.0) * sum;
}

double simpsonsThreeEighth(int n) {
    if (n % 3 != 0) {
        cout << "Simpson's 3/8 rule requires n divisible by 3.\n";
        return 0.0;
    }

    double a = 0.0, b = 1.0;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 3 == 0 ? 2.0 : 3.0) * f(x);
    }

    return (3.0 * h / 8.0) * sum;
}

void runAllMethods() {
    double exact = exactIntegral();
    cout << fixed << setprecision(10);

    cout << "\n--- Trapezoidal Rule ---\n";
    for (int n : {10, 100, 200}) {
        double approx = trapezoidalRule(n);
        cout << "n = " << n << ", Approx = " << approx
             << ", Error = " << fabs(exact - approx) << endl;
    }

    cout << "\n--- Simpson's 1/3 Rule ---\n";
    for (int n : {10, 100, 200}) {
        double approx = simpsonsOneThird(n);
        cout << "n = " << n << ", Approx = " << approx
             << ", Error = " << fabs(exact - approx) << endl;
    }

    cout << "\n--- Simpson's 3/8 Rule ---\n";
    for (int n : {12, 120, 240}) {
        double approx = simpsonsThreeEighth(n);
        cout << "n = " << n << ", Approx = " << approx
             << ", Error = " << fabs(exact - approx) << endl;
    }
}

int main() {
    runAllMethods();
    return 0;
}
