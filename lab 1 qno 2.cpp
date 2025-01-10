#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - x - 2;  
}

double df(double x) {
    return 3 * pow(x, 2) - 1;  
}

void newtonMethod(double x0, double tol = 1e-6, int maxIter = 100) {
    double x = x0;  
    int iterCount = 0;

    while (iterCount < maxIter) {
        iterCount++;
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {  
            cout << "Derivative is too small. The method may fail." << endl;
            return;
        }

        double x_new = x - fx / dfx;  

        if (fabs(x_new - x) < tol) {
            x = x_new;
            break;
        }

        x = x_new;  
}\
    cout << "Estimated root: " << fixed << setprecision(6) << x << endl;
    cout << "Functional value at the root: " << fixed << setprecision(6) << f(x) << endl;
    cout << "Number of iterations: " << iterCount << endl;
}

int main() {
    double x0;

    // Input initial guess from the user
    cout << "Non-linear Equation Solving using Newton's Method" << endl;
    cout << "Enter the initial guess: ";
    cin >> x0;

    // Call the Newton's Method
    newtonMethod(x0);

    return 0;
}

