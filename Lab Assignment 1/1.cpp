#include <bits/stdc++.h>

using namespace std;

int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    cout << "Significant digits: " << count << endl;
    return 0;
}
