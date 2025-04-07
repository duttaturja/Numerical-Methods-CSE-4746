#include <bits/stdc++.h>
using namespace std;

int p, q, r, s, t, u;

double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double solve() {
    double lo = 0.0, hi = 1.0, mid;
    for (int i = 0; i < 100; i++) {
        mid = (lo + hi) / 2;
        if (f(lo) * f(mid) <= 0)
            hi = mid;
        else
            lo = mid;
    }
    return (lo + hi) / 2;
}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (f(0) * f(1) > 0) {
            cout << "No solution\n";
        } else {
            double ans = solve();
            cout << fixed << setprecision(4) << ans << "\n";
        }
    }
    return 0;
}
