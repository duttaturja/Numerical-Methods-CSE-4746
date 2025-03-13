#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - x + 2;
}

void falsePosition(double a, double b) {
    double c;
    while (abs(f(c)) > 0.001) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Root: " << c << endl;
}

int main() {
    falsePosition(-3, 3);
    return 0;
}
