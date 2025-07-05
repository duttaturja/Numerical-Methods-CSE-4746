
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double f[6][5], h = 1, x0 = 1, x = 1.5;
    double u = (x - x0) / h;

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
        for(int j = 0; j <= 5 - i; j++) cout << f[i][j] << '\t';
        cout << endl;
    }
    double first_der = 0, second_der = 0;

    first_der += 1 / h * (f[1][1] - (2 * u - 1) * f[1][2] / 2.0 +  (3.0 * u * u - 6 * u + 2.0) / 6.0 * f[1][3]);
    second_der += 1 / (h * h) * (f[1][2] + (u - 1) * f[1][3] + (6.0 * u * u - 18.0 * u + 11.0) / 12.0 * f[1][4]);
    cout << endl << "The First Derivative is: " << first_der << endl;
    cout << endl << "The Second Derivative is: " << second_der << endl;
}
