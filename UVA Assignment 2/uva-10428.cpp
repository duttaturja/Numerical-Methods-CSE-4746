#include <bits/stdc++.h> 
using namespace std; 
#define EPS 1e-7 
vector<double> QuotientPolynomial(int degree, double root, vector<double>p_X) 
{ 
vector<double>q_X(degree + 1, 0.0); 
for (int i = degree - 1; i >= 0; i--) { 
q_X[i] = p_X[i + 1] + root * q_X[i + 1]; 
} 
return q_X; 
} 
double fX(int degree, double x, vector<double>p_X) 
{ 
double ans = 0.0; 
for (int i = degree; i >= 0; i--) { 
ans += p_X[i] * pow(x, i); 
} 
return ans; 
} 
double dX(int degree, double x, vector<double>p_X) 
{ 
double ans = 0.0; 
for (int i = degree; i >= 1; i--) { 
ans += p_X[i] * i * pow(x, i - 1); 
} 
return ans; 
} 
double NewtonRaphson(int degree, vector<double>p_X) 
{ 
double x, x0; 
x0 = -25.0; 
while (true) { 
x = x0 - fX(degree, x0, p_X) / dX(degree, x0, p_X); 
if (fabs(x - x0) < EPS) { 
break; 
        } 
        x0 = x; 
    } 
    return x; 
} 
 
int main() 
{ 
 
 
    int n, i, test = 1; 
    double x; 
    vector<double>allP, allRoot; 
 
    while (cin >> n) { 
        if (!n) { 
            break; 
        } 
 
        allP.clear(); 
        allP.assign(n + 1, 0.0); 
        for (i = n; i >= 0; i--) { 
            cin >> allP[i]; 
        } 
 
        allRoot.clear(); 
        for (i = n; i >= 1; i--) { 
            x = NewtonRaphson(i, allP); 
            allRoot.push_back(x); 
            allP = QuotientPolynomial(i, x, allP); 
        } 
 
        sort(allRoot.begin(), allRoot.end()); 
        cout << "Equation " << test++ << ":"; 
        for (i = 0; i < n; i++) { 
            cout << " " << setprecision(4) << fixed << allRoot[i]; 
        } 
        cout << "\n"; 
    } 
 
    return 0; 
}
