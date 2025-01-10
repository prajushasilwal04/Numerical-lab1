#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - x - 2;  
}


void bisectionMethod(double a, double b, double tol = 1e-6, int maxIter = 100) {
    if (f(a) * f(b) >= 0) {
        cout << "The function does not have a root in this interval." << endl;
        return;
    }

    double c;  
    int iterCount = 0;

    while ((b - a) / 2.0 > tol && iterCount < maxIter) {
        iterCount++;
        c = (a + b) / 2.0;  
        if (f(c) == 0) {  
            break;
        } else if (f(a) * f(c) < 0) {
            b = c; 
        } else {
            a = c;  
        }
    }

    cout << "Estimated root: " << fixed << setprecision(6) << c << endl;
    cout << "Functional value at the root: " << fixed << setprecision(6) << f(c) << endl;
    cout << "Number of iterations: " << iterCount << endl;
}

int main() {
    double a, b;

    cout << "Non-linear Equation Solving using Bisection Method" << endl;
    cout << "Enter the initial guess a (left endpoint of the interval): ";
    cin >> a;
    cout << "Enter the initial guess b (right endpoint of the interval): ";
    cin >> b;

    bisectionMethod(a, b);

    return 0;
}

