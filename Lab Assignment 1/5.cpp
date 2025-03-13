#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x - 6*x + 4;
}

double bisection(double a, double b, double tol) {
    double mid;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval [" << a << ", " << b << "] for Bisection." << endl;
        return 0.0;
    }

    while ((b - a) >= tol) {
        mid = (a + b) / 2.0;
        double fm = f(mid);

        if (fabs(fm) < tol)
            break;

        if (f(a) * fm < 0)
            b = mid;
        else
            a = mid;
    }
    return (a + b) / 2.0;
}

int main() {
    cout << fixed << setprecision(3);

    double root1 = bisection(-3.0, -2.0, 0.001);
    double root2 = 2.0;  
    double root3 = bisection(0.0, 1.0, 0.001);

    cout << "Root 1: " << root1 << endl;
    cout << "Root 2: " << root2 << endl;
    cout << "Root 3: " << root3 << endl;

    return 0;
}
