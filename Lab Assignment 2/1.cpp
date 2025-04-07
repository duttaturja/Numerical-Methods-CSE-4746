#include<bits/stdc++.h> 
using namespace std; 
int main() { 
    int n = 5; 
    int x[] = {1, 2, 3, 4, 5}; 
    int y[n][n]; 
    for(int i = 0; i < n; i++) { 
        y[i][0] = pow(x[i], 3);  
    } 
    for(int j = 1; j < n; j++) { 
        for(int i = 0; i < n - j; i++) { 
            y[i][j] = y[i+1][j-1] - y[i][j-1]; 
        } 
    } 
    cout << "Difference Table:\n"; 
    for(int i = 0; i < n; i++) { 
        cout << setw(4) << x[i]; 
        for(int j = 0; j < n - i; j++) { 
            cout << setw(10) << y[i][j]; 
        } 
        cout << endl; 
    } 
    return 0; 
}