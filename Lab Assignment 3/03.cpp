
#include <bits/stdc++.h>
using namespace std;
#define ll long long

double f(double x) {
    return log10(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a = 1, b = 5;
    ll n = 5;
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    double integral = h * sum;
    cout << "Approximate area = " << integral << endl;
}
