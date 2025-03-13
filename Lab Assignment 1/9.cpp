#include<bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> coef = {1, -5, 10, -8};
    int divisor = 2;
    int n = coef.size();
    
    vector<int> quotient(n - 1);
    quotient[0] = coef[0];
    for (int i = 1; i < n - 1; i++) {
        quotient[i] = quotient[i - 1] * divisor + coef[i];
    }
    
    cout << "Quotient polynomial: ";
    int degree = quotient.size() - 1;
    for (int i = 0; i < quotient.size(); i++) {
        int coeff = quotient[i];
        int currentDegree = degree - i;
        
        if (i == 0) {
            if (coeff < 0)
                cout << "-";
        } else {
            
            if (coeff < 0)
                cout << " - ";
            else
                cout << " + ";
        }
        
        int absCoeff = abs(coeff);
        if (absCoeff != 1 || currentDegree == 0)
            cout << absCoeff;
        
        if (currentDegree > 0) {
            cout << "x";
            if (currentDegree > 1)
                cout << "^" << currentDegree;
        }
    }
    
    cout << endl;
    return 0;
}