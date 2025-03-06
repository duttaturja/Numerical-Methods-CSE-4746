#include <bits/stdc++.h>

using namespace std;

double f(int p, int q, int r, int s, int t, int u, double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double findRoot(int p, int q, int r, int s, int t, int u) {
    double left = 0.0, right = 1.0, mid;

    if (f(p, q, r, s, t, u, left) * f(p, q, r, s, t, u, right) > 0) {
        return -1;
    }

    for (int i = 0; i < 50; i++) {
        mid = (left + right) / 2.0;
        double val = f(p, q, r, s, t, u, mid);

        if (fabs(val) < 1e-7) break;
        if (f(p, q, r, s, t, u, left) * val < 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}

int main() {
    int p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u) {
        double root = findRoot(p, q, r, s, t, u);
        if (root == -1)
            cout << "No solution" << endl;
        else
            printf("%.4f\n", root);
    }
    return 0;
}
