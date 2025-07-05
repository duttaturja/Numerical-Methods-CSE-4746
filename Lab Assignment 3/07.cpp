
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll> > mulMat(ll r1, ll r2, ll c1, ll c2, vector<vector<ll> > a,
                            vector<vector<ll>> b)
{
    if (c1 != r2) {
        cout << "Invalid Input" << endl;
        exit(EXIT_FAILURE);
    }
    vector<vector<ll> > res(r1, vector<ll> (c2, 0));
    for (int i = 1; i < r1; i++) {
        for (int j = 1; j < c2; j++) {
            for (int k = 1; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

double getMinor(vector<vector<ll>> mat, ll row, ll col) {
    ll rows[2], cols[2];
    ll r_idx = 0;
    for (int i = 1; i <= 3; i++) {
        if (i == row) continue;
        rows[r_idx++] = i;
    }
    ll c_idx = 0;
    for (int j = 1; j <= 3; j++) {
        if (j == col) continue;
        cols[c_idx++] = j;
    }
    ll a = mat[rows[0]][cols[0]];
    ll b = mat[rows[0]][cols[1]];
    ll c = mat[rows[1]][cols[0]];
    ll d = mat[rows[1]][cols[1]];
    return (a * d - b * c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<ll> > a(4, vector<ll> (4)), b(4, vector<ll> (2)), cofactor(4,
        vector<ll> (4)),  adjoint(4, vector<ll> (4));

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 3; i++)
    {
        cin >> b[i][1];
    }

    ll diter = a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] + a[1][3] * a[2][1] * a[3][2]
             - (a[3][1] * a[2][2] * a[1][3] + a[3][2] * a[2][3] * a[1][1] + a[3][3] * a[2][1] * a[1][2]);

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            ll minor = getMinor(a, i, j);
            ll sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            cofactor[i][j] = sign * minor;
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            adjoint[i][j] = cofactor[j][i];
        }
    }
    vector<vector<ll> > ans = mulMat(4, 4, 4, 2, adjoint, b);
    for(int i = 1; i < ans.size(); i++)
    {
        for(int j = 1; j < ans[i].size(); j++)
        {
            double x = ans[i][j] / (1.0 * diter);
            cout << x << " ";
        }
        cout << endl;
    }
}
