#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - x - 2;  
}


void secantMethod(double x0, double x1, double tol = 1e-6, int maxIter = 100) {
    int iterCount = 0;
    double x2;

    while (iterCount < maxIter) {
        iterCount++;
        
        double fx0 = f(x0);
        double fx1 = f(x1);
        
        if (fabs(fx1 - fx0) < 1e-12) {
            cout << "The method fails due to a small difference in function values." << endl;
            return;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        
        if (fabs(x2 - x1) < tol) {
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "Estimated root: " << fixed << setprecision(6) << x2 << endl;
    cout << "Functional value at the root: " << fixed << setprecision(6) << f(x2) << endl;
    cout << "Number of iterations: " << iterCount << endl;
}

int main() {
    double x0, x1;

    cout << "Non-linear Equation Solving using Secant Method" << endl;
    cout << "Enter the first initial guess x0: ";
    cin >> x0;
    cout << "Enter the second initial guess x1: ";
    cin >> x1;

    secantMethod(x0, x1);

    return 0;
}

