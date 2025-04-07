#include<bits/stdc++.h> 
using namespace std; 
int main() { 
    int n = 5; 
    double x[] = {1, 3, 4, 6, 10}; 
    double y[n][n] = { 
        {0}, {18}, {58}, {190}, {920} 
    }; 
    for(int j = 1; j < n; j++) { 
        for(int i = 0; i < n - j; i++) { 
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]); 
        } 
    } 
    cout << "Divided Difference Table:\n"; 
    for(int i = 0; i < n; i++) { 
        cout << x[i] << "\t"; 
        for(int j = 0; j < n - i; j++) { 
            cout << y[i][j] << "\t"; 
        } 
        cout << endl; 
    } 
    double value = 2.7; 
    double result = y[0][0]; 
    double term = 1; 
    for(int i = 1; i < n; i++) { 
        term *= (value - x[i-1]); 
        result += term * y[0][i]; 
    } 
    cout << "\nEstimated value of f(2.7) is " << result << endl; 
    return 0; 
} 
