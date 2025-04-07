#include<bits/stdc++.h> 
using namespace std; 
int main() { 
    int n = 5; 
    double x[] = {1, 2, 3, 4, 5}; 
    double y[] = {1, 8, 27, 64, 125}; 
    double y_given = 85; 
    double result = 0; 
    for (int i = 0; i < n; i++) { 
        double term = x[i]; 
        for (int j = 0; j < n; j++) { 
            if (j != i) 
                term *= (y_given - y[j]) / (y[i] - y[j]); 
        } 
        result += term; 
    } 
    cout << "Estimated value of x for f(x) = 85 is " << result << endl; 
    return 0; 
}