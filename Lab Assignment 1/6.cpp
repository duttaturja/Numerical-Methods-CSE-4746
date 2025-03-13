#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - 6 * x + 4;
}

double df(double x) {
    return 3 * x * x - 6;
}

void newtonRaphson(double x) {
    double h = f(x) / df(x);
    while (abs(h) >= 0.001) {
        h = f(x) / df(x);
        x = x - h;
    }
    cout << "Root: " << x << endl;
}

int main() {
    newtonRaphson(2);
    return 0;
}
