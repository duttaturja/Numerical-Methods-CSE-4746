
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dit3X3(vector<vector<ll>> a)
{
    return a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] + a[1][3] *
           a[2][1] * a[3][2] - (a[3][1] * a[2][2] * a[1][3] + a[3][2] * a[2][3] * a[1][1] +
           a[3][3] * a[2][1] * a[1][2]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<ll>> a(4, vector<ll>(4)), b(4, vector<ll>(2));

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        cin >> b[i][1];
    }

    ll D = dit3X3(a);

    for (int i = 1; i <= 3; i++)
    {
        vector<vector<ll> > temp(4, vector<ll> (4));
        for (int j = 1; j <= 3; j++)
        {
            for(int k = 1; k <= 3; k++)
            {
                if(i == k)
                {
                    temp[j][k] = b[j][1];
                }
                else
                {
                    temp[j][k] = a[j][k];
                }
            }
        }
        ll diter = dit3X3(temp);
        double ans = (1.0 * diter) / (1.0 * D);
        cout << ans << endl;
    }
}
