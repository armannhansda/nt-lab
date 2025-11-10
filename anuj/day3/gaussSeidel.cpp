#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n)); // Coefficient matrix
    vector<double> b(n), x(n, 0);                   // RHS and initial guesses
    double tol;
    int maxIter;

    cout << "Enter the coefficients of matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the constants vector b:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Enter tolerance: ";
    cin >> tol;

    cout << "Enter maximum number of iterations: ";
    cin >> maxIter;

    cout << "\nIteration\tx1\t\tx2\t\tx3 ...\n";
    cout << "-------------------------------------------\n";

    vector<double> x_old(n, 0);
    bool converged = false;
    int iter = 0;

    while (iter < maxIter) {
        x_old = x; // Save previous iteration

        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j]; // Uses most recent x[j]
            }
            x[i] = sum / a[i][i];
        }

        cout << iter + 1 << "\t";
        for (int i = 0; i < n; i++) {
            cout << x[i] << "\t";
        }
        cout << endl;

        // Check convergence
        converged = true;
        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - x_old[i]) > tol) {
                converged = false;
                break;
            }
        }

        if (converged)
            break;

        iter++;
    }

    if (converged) {
        cout << "\nSolution converged in " << iter + 1 << " iterations.\n";
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x[i] << endl;
        }
    } else {
        cout << "\nThe method did not converge within " << maxIter << " iterations.\n";
    }

    return 0;
}
