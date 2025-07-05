
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1)

double f(double x)
{
    return exp(sin(x));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a = 0.0;
    double b = pi / 2.0;
    ll n;
    cin >> n; // number of intervals

    if (n % 2 != 0) n += n % 2;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 1)
            sum += 4 * f(x);
        else
            sum += 2 * f(x);
    }
    double integral = (h / 3.0) * sum;
    cout << "Approximate area = " << integral << endl;
}
