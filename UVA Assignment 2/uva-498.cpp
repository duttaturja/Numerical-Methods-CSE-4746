#include <bits/stdc++.h>
using namespace std;

void parse(string line, vector<int> &v) {
    int num = 0;
    bool neg = false;
    v.clear();

    for (int i = 0; i <= line.size(); i++) {
        char ch = (i < line.size()) ? line[i] : ' ';

        if (ch == '-') neg = true;
        else if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        }
        else if (ch == ' ' || i == line.size()) {
            if (neg) num = -num;
            v.push_back(num);
            num = 0;
            neg = false;
        }
    }
}

int main() {
    string line1, line2;
    vector<int> coeffs, xvals;

    while (getline(cin, line1)) {
        getline(cin, line2);

        parse(line1, coeffs);
        parse(line2, xvals);

        for (int i = 0; i < xvals.size(); i++) {
            int x = xvals[i];
            int res = 0;
            for (int j = 0; j < coeffs.size(); j++) {
                res = res * x + coeffs[j];
            }
            cout << res << " ";
        }
        cout << "\n";
    }

    return 0;
}
