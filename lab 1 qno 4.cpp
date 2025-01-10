#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double x) {
    return pow(x, 3) + 2 * x - 5;  // Example: g(x) = x^3 + 2x - 5
}

void fixedPointIteration(double x0, double tol = 1e-6, int maxIter = 100) {
    int iterCount = 0;
    double x1;

    while (iterCount < maxIter) {
        iterCount++;
        x1 = g(x0);
        
        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
    }

    cout << "Estimated root: " << fixed << setprecision(6) << x1 << endl;
    cout << "Functional value at the root: " << fixed << setprecision(6) << g(x1) << endl;
    cout << "Number of iterations: " << iterCount << endl;
}

int main() {
    double x0;
    cout << "Enter the initial guess: ";
    cin >> x0;
    fixedPointIteration(x0);
    return 0;
}

