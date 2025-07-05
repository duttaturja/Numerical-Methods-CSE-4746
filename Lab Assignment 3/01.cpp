
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll f[6][5], h = 1, x0 = 1, x = 1;

    f[1][0] = 1;
    f[2][0] = 8;
    f[3][0] = 27;
    f[4][0] = 64;
    f[5][0] = 125;

    for(int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 6 - i; j++)
        {
            f[j][i] = f[j + 1][i - 1] - f[j][i - 1];
        }
    }
    cout << "Difference Table" << endl;
    for(int i = 1; i <= 5; i++)
    {
        cout << i << '\t';
        for(int j = 0; j <= 5 - i; j++)
        {
            cout << f[i][j] << '\t';
        }
        cout << endl;
    }

    ll first_der = 0, second_der = 0, mul = 1;

    for(int i = 1; i < 5; i++)
    {
        first_der += mul * (f[1][i] / i);
        mul *= -1;
    }

    first_der *= (1 / h);
    cout << endl << "The First Derivative is: " << first_der << endl;
    mul = 1;

    for(int i = 2; i < 5; i++)
    {
        if(i > 3)
        {
            second_der +=  mul * (11 * (f[1][i])) / 12;
        }
        else
        {
            second_der += mul * (f[1][i]);
        }
        mul *= -1;
    }

    first_der *= (1 / (h * h));
    cout << endl << "The Second Derivative is: " << second_der << endl;
}
