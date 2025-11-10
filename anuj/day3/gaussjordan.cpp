#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1)); // Augmented matrix

    cout << "Enter the augmented matrix (A|b):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Gauss–Jordan Elimination
    for (int i = 0; i < n; i++) {
        // Pivoting (make the diagonal element 1)
        if (fabs(a[i][i]) < 1e-12) {
            bool swapped = false;
            for (int k = i + 1; k < n; k++) {
                if (fabs(a[k][i]) > 1e-12) {
                    swap(a[i], a[k]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                cout << "No unique solution exists (singular matrix)." << endl;
                return 0;
            }
        }

        double pivot = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= pivot;
        }

        // Make all other entries in this column zero
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    cout << "\nThe solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << a[i][n] << endl;
    }

    return 0;
}
