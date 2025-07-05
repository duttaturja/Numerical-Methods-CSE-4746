
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1)

double f(double x) { return x / (1.0 + x*x); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a = 0, b = 1;
    ll n;
    cin >> n;

    if (n % 3 != 0) {
        n = n + (3 - n % 3);
        cout << "New value of n: " << n << endl;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }
    double integral = (3 * h / 8) * sum;
    cout << "Approximate area = " << integral << endl;
}
