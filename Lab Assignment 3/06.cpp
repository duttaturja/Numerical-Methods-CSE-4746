
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a[4][4];

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }

    ll ans = a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] + a[1][3] * a[2][1] * a[3][2]
           - (a[3][1] * a[2][2] * a[1][3] + a[3][2] * a[2][3] * a[1][1] + a[3][3] * a[2][1] * a[1][2]);
    cout << ans << endl;
}
