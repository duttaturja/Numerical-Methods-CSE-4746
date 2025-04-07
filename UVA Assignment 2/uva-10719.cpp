#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string line;
    while (cin >> k) {
        cin.ignore(); // skip newline
        getline(cin, line);

        vector<int> a;
        int i = 0, n = line.size();
        while (i < n) {
            while (i < n && line[i] == ' ') i++;

            int sign = 1;
            if (i < n && line[i] == '-') {
                sign = -1;
                i++;
            }

            int num = 0;
            bool found = false;
            while (i < n && isdigit(line[i])) {
                num = num * 10 + (line[i] - '0');
                i++;
                found = true;
            }

            if (found) a.push_back(sign * num);
        }

        int sz = a.size();
        if (sz == 0) continue;

        vector<int> q;
        q.push_back(a[0]);

        for (int i = 1; i < sz - 1; i++) {
            q.push_back(a[i] + k * q.back());
        }

        // output q(x):
        cout << "q(x):";
        for (int i = 0; i < q.size(); i++) {
            cout << (i == 0 ? " " : " ") << q[i];
        }
        cout << "\n";

        // output r
        int r = (sz == 1) ? a[0] : a[sz - 1] + k * q.back();
        cout << "r = " << r << "\n";
    }

    return 0;
}
