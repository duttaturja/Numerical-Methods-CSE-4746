#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    vector<int> vec;
    
    cout << "Enter numbers from line of text: ";
    getline(cin, str);
    
    int num = 0;
    bool has_number = false;
    
    for (char ch : str) {
        if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0');
            has_number = true;
        }
        else if (ch == ' ' && has_number)
        {
            vec.push_back(num);
            num = 0;
            has_number = false;
        }
    }
    
    if (has_number) {
        vec.push_back(num);
    }

    int y = vec.size();
    int x = vec[y-1];
    vec.pop_back();

    cout << "\nInteger Array: [";
    for (int n : vec) {
        cout << n << ", ";
    }
    cout << x<< "]"<< endl;
    
    return 0;
}
