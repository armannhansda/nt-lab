#include <iostream>
#include <vector>
using namespace std;

// Function to perform Lagrange Interpolation
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double xp) {
    int n = x.size();
    double yp = 0.0; // interpolated value

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term;
    }

    return yp;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the data points (x and y):\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    double xp;
    cout << "Enter the value of x for interpolation: ";
    cin >> xp;

    double yp = lagrangeInterpolation(x, y, xp);

    cout << "\nThe interpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
