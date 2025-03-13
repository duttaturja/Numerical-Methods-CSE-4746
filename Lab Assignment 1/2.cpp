#include <bits/stdc++.h>
using namespace std;


int main() {
    double num, ans;
    int x;
    cout << "Enter number: ";
    cin >> num;
    cout << "Enter significant figures: ";
    cin >> x;
    double factor = pow(10, x - 1);
    ans = round(num * factor) / factor;
    cout << "Rounded number: " << ans << endl;
    return 0;
}
