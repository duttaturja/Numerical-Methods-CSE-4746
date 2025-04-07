#include <bits/stdc++.h>
using namespace std;

double a[25]; 
double root[25];
int root_cnt;

int n;
double l, r;


double f(double x) {
    double res = 0, p = 1;
    for (int i = n; i >= 0; i--) {
        res += a[i] * p;
        p *= x;
    }
    return res;
}

double bisection(double x1, double x2) {
    double mid;
    for (int i = 0; i < 100; i++) {
        mid = (x1 + x2) / 2;
        double f1 = f(x1);
        double fmid = f(mid);
        if (fabs(fmid) < 1e-7) break;
        if (f1 * fmid < 0) x2 = mid;
        else x1 = mid;
    }
    return mid;
}

int main() {
    while (cin >> n) {
        for (int i = n; i >= 0; i--) {
            cin >> a[i];
        }
        cin >> l >> r;

        double step = (r - l) / 10000.0;
        double x1 = l;
        root_cnt = 0;

        while (x1 < r) {
            double x2 = x1 + step;
            double y1 = f(x1), y2 = f(x2);

            if (y1 * y2 <= 0) {
                double rt = bisection(x1, x2);

                
                if (root_cnt == 0 || fabs(rt - root[root_cnt - 1]) > 1e-4) {
                    root[root_cnt++] = rt;
                }
            }
            x1 = x2;
        }

        for (int i = 0; i < root_cnt; i++) {
            printf(" %.4f", root[i]);
        }
        printf("\n");
    }
    return 0;
}
