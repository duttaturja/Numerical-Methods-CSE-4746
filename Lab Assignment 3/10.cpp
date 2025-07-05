
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double a[4][5];
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            cin >> a[i][j];
        }
    }

    ll n = 3;
    for (int p = 1; p <= n; p++)
    {
        int max_row = p;
        for (int i = p + 1; i <= n; i++)
        {
            if (abs(a[i][p]) > abs(a[max_row][p]))
            {
                max_row = i;
            }
        }
        for (int j = 1; j <= n + 1; j++)
        {
            swap(a[p][j], a[max_row][j]);
        }
        double div = a[p][p];
        for (int j = p; j <= n + 1; j++)
        {
            a[p][j] /= div;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i != p)
            {
                double factor = a[i][p];
                for (int j = p; j <= n + 1; j++)
                {
                    a[i][j] -= factor * a[p][j];
                }
            }
        }
    }
    cout << "Solution: " << endl;
    cout << "x = " << fixed << setprecision(2) << a[1][4] << endl;
    cout << "y = " << fixed << setprecision(2) << a[2][4] << endl;
    cout << "z = " << fixed << setprecision(2) << a[3][4] << endl;
}
