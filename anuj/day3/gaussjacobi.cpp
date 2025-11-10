#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n)); // Coefficient matrix
    vector<double> b(n), x(n, 0), x_new(n, 0);      // RHS and solution vectors
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

    int iter = 0;
    bool converged = false;

    while (iter < maxIter) {
        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
        }

        cout << iter + 1 << "\t";
        for (int i = 0; i < n; i++) {
            cout << x_new[i] << "\t";
        }
        cout << endl;

        // Check for convergence
        converged = true;
        for (int i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > tol) {
                converged = false;
                break;
            }
        }

        if (converged)
            break;

        x = x_new;
        iter++;
    }

    if (converged) {
        cout << "\nSolution converged in " << iter + 1 << " iterations.\n";
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x_new[i] << endl;
        }
    } else {
        cout << "\nThe method did not converge within " << maxIter << " iterations.\n";
    }

    return 0;
}
