
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n = 3;
    vector<vector<double> > a(4, vector<double> (5));

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int p = 1; p <= n - 1; p++) {
        for (int i = p + 1; i <= n; i++) {
            double factor = a[i][p] / a[p][p];
            for (int j = p; j <= n + 1; j++) {
                a[i][j] -= factor * a[p][j];
            }
        }
    }

    double x[4] = {0};
    for (int i = n; i >= 1; i--) {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    cout << "Solution:" << endl;
    cout << "x = " << fixed << setprecision(3) << x[1] << endl;
    cout << "y = " << fixed << setprecision(3) << x[2] << endl;
    cout << "z = " << fixed << setprecision(3) << x[3] << endl;
}
