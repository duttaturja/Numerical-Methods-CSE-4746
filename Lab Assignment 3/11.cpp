
#include <bits/stdc++.h>
using namespace std;
#define ll long long

double value_x(double x, double y, double z)
{
    return (95.0 - 11.0 * y + 4 * z) / 83.0;
}

double value_y(double x, double y, double z)
{
    return (104.0 - 7.0 * x - 13 * z) / 52.0;
}

double value_z(double x, double y, double z)
{
    return (104.0 - 3.0 * x + 8 * y) / 29.0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x = 0, y = 0, z = 0, eps = 1e-4;

    while (1)
    {
        double new_x = value_x(x, y, z);
        double new_y = value_y(x, y, z);
        double new_z = value_z(x, y, z);

        if (fabs(new_x - x) > eps || fabs(new_y - y) > eps || fabs(new_z - z) > eps)
        {
            x = new_x;
            y = new_y;
            z = new_z;
        }
        else
        {
            x = new_x;
            y = new_y;
            z = new_z;
            break;
        }
    }

    cout << "Solution: " << endl;
    cout << "x = " << fixed << setprecision(4) << x << endl;
    cout << "y = " << fixed << setprecision(4) << y << endl;
    cout << "z = " << fixed << setprecision(4) << z << endl;
}
