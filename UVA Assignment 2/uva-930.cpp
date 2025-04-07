#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int deg;
        cin >> deg;

        double coef[130];
        for (int i = deg; i >= 0; i--) {
            cin >> coef[i];
        }

        // Modify the polynomial using values (deg - 2) times
        for (int i = 0; i < deg - 2; i++) {
            double val;
            cin >> val;

            double prev = coef[deg];
            for (int j = deg - 1; j >= 0; j--) {
                coef[j] = coef[j] + prev * val;
                prev = coef[j];
            }
        }

        double a = coef[deg];
        double b = coef[deg - 1];
        double c = coef[deg - 2];

        // Solve quadratic
        double d = b * b - 4 * a * c;
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);

        // Output roots with 1 decimal place
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << r1 << "\n" << r2 << "\n";
    }

    return 0;
}