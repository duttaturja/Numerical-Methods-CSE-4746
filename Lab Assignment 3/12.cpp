
#include <bits/stdc++.h>
using namespace std;
#define ll long long

double value_x(double x, double y, double z)
{
    return (12.0 - y - z) / 10.0;
}

double value_y(double x, double y, double z)
{
    return (13.0 - 2.0 * x - z) / 10.0;
}

double value_z(double x, double y, double z)
{
    return (14.0 - 2.0 * x + 2 * y) / 10.0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x = 0, y = 0, z = 0, eps = 1e-4;

    while (1)
    {
        double new_x = value_x(x, y, z);
        double new_y = value_y(new_x, y, z);  // Gauss-Seidel uses updated x
        double new_z = value_z(new_x, new_y, z); // and updated y

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
    cout << "x1 = " << fixed << setprecision(4) << x << endl;
    cout << "x2 = " << fixed << setprecision(4) << y << endl;
    cout << "x3 = " << fixed << setprecision(4) << z << endl;
}
