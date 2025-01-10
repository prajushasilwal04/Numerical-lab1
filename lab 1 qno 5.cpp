#include <iostream>
#include <vector>

using namespace std;

double hornerMethod(const vector<double>& coeffs, double x) {
    double result = coeffs[0];
    for (size_t i = 1; i < coeffs.size(); ++i) {
        result = result * x + coeffs[i];
    }
    return result;
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coeffs(degree + 1);
    cout << "Enter the coefficients of the polynomial: ";
    for (int i = 0; i <= degree; ++i) {
        cin >> coeffs[i];
    }

    double x;
    cout << "Enter the value of x: ";
    cin >> x;

    double result = hornerMethod(coeffs, x);
    cout << "Polynomial value at x = " << x << " is " << result << endl;

    return 0;
}

