#include <iostream>
using namespace std;

// Define the derivative function dy/dx = f(x, y)
double f(double x, double y) {
    // Example: dy/dx = x + y
    return x + y;
}

int main() {
    double x0, y0, xn, h;

    cout << "Enter initial value x0: ";
    cin >> x0;
    cout << "Enter initial value y0: ";
    cin >> y0;
    cout << "Enter final value xn: ";
    cin >> xn;
    cout << "Enter step size h: ";
    cin >> h;

    int n = (xn - x0) / h; // number of steps
    double x = x0, y = y0;

    cout << "\nRunge-Kutta 4th Order Table:\n";
    cout << "x\t\ty\n";
    cout << x << "\t" << y << endl;

    for (int i = 1; i <= n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x = x + h;

        cout << x << "\t" << y << endl;
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y << endl;

    return 0;
}
