#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - 9 * x + 1;
}

void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval!" << endl;
        return;
    }
    
    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Root: " << c << endl;
}

int main() {
    bisection(-1, 1, 0.001);
    return 0;
}
