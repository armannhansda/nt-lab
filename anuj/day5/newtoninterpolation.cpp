#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to compute factorial
long long fact(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

// Newton Forward Interpolation
double newtonForward(const vector<double>& x, const vector<double>& y, double xp) {
    int n = x.size();
    vector<vector<double>> diff(n, vector<double>(n));

    // Construct forward difference table
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

    double h = x[1] - x[0]; // uniform spacing
    double p = (xp - x[0]) / h;

    double yp = y[0];
    for (int i = 1; i < n; i++) {
        double term = p;
        for (int j = 1; j < i; j++)
            term *= (p - j);
        yp += (term * diff[0][i]) / fact(i);
    }

    cout << "\nForward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << setw(10) << diff[i][j] << " ";
        cout << endl;
    }

    return yp;
}

// Newton Backward Interpolation
double newtonBackward(const vector<double>& x, const vector<double>& y, double xp) {
    int n = x.size();
    vector<vector<double>> diff(n, vector<double>(n));

    // Construct backward difference table
    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];
    for (int j = 1; j < n; j++)
        for (int i = n - 1; i >= j; i--)
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];

    double h = x[1] - x[0]; // uniform spacing
    double p = (xp - x[n - 1]) / h;

    double yp = y[n - 1];
    for (int i = 1; i < n; i++) {
        double term = p;
        for (int j = 1; j < i; j++)
            term *= (p + j);
        yp += (term * diff[n - 1][i]) / fact(i);
    }

    cout << "\nBackward Difference Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << setw(10) << diff[i][j] << " ";
        cout << endl;
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
    cout << "\nEnter the value of x for interpolation: ";
    cin >> xp;

    cout << "\nChoose method:\n1. Newton Forward\n2. Newton Backward\nEnter choice: ";
    int choice;
    cin >> choice;

    double yp;
    if (choice == 1)
        yp = newtonForward(x, y, xp);
    else
        yp = newtonBackward(x, y, xp);

    cout << fixed << setprecision(6);
    cout << "\nInterpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
