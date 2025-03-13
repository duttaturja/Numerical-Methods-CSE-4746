#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - 5 * x * x - 29;
}

void secant(double x1, double x2) {
    double x3;
    while (abs(x2 - x1) > 0.001) {
        x3 = x2 - (f(x2) * (x2 - x1)) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;
    }
    cout << "Root: " << x3 << endl;
}

int main() {
    secant(2, 3);
    return 0;
}
