#include <bits/stdc++.h>

using namespace std;

int calculatePolynomial(const vector<int>& vec, int x) {
    int result = 0;
    int n = vec.size() - 1;

    for (int i = 0; i <= n; i++) {
        result += vec[i] * pow(x, n - i);
    }
    return result;
}

int main() {
    vector<int> vec, x_values;
    int num;

    while (cin) {
        vec.clear();
        x_values.clear();

        while (cin >> num) {
            vec.push_back(num);
            if (cin.peek() == '\n') break;
        }

        while (cin >> num) {
            x_values.push_back(num);
            if (cin.peek() == '\n') break;
        }

        for (size_t i = 0; i < x_values.size(); i++) {
            cout << calculatePolynomial(vec, x_values[i]) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
