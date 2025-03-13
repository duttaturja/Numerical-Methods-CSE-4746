#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x - 6*x + 4;
}

double df(double x) {
    return 3*x*x - 6;
}

double newtonRaphson(double x) {
    double h;
    do {
        h = f(x) / df(x);
        x = x - h;
    } while (fabs(h) >= 0.001);
    return x;
}

int main() {
    
    double root1 = newtonRaphson(2);
    cout << "Root 1: " << root1 << endl;

    double a = 1, b = 0, c = -6, d = 4; 
    double b_new = b + a * root1;
    double c_new = c + b_new * root1;

    double discriminant = b_new*b_new - 4*c_new;
    if (discriminant >= 0) {
        double root2 = (-b_new + sqrt(discriminant)) / 2;
        double root3 = (-b_new - sqrt(discriminant)) / 2;
        cout << "Root 2: " << root2 << endl;
        cout << "Root 3: " << root3 << endl;
    } else {
        cout << "The remaining roots are complex numbers." << endl;
    }

    return 0;
}

