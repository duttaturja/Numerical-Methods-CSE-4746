#include<bits/stdc++.h> 
using namespace std; 
int main() { 
    int n = 5; 
    double x[] = {1, 2, 3, 4, 5}; 
    double y[n][n]; 
    for(int i = 0; i < n; i++) { 
        y[i][0] = pow(x[i], 3); 
    } 
    for(int j = 1; j < n; j++) { 
        for(int i = 0; i < n - j; i++) { 
            y[i][j] = y[i+1][j-1] - y[i][j-1]; 
        } 
    } 
    double value = 1.7; 
    double h = x[1] - x[0]; 
    double u = (value - x[0]) / h; 
    double result = y[0][0]; 
    double term = 1; 
    for(int i = 1; i < n; i++) { 
        term *= (u - i + 1) / i; 
        result += term * y[0][i]; 
    } 
    cout << "Estimated value at x = 1.7 is " << result << endl; 
    return 0; 
}