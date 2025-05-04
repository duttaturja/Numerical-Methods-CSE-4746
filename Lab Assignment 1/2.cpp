#include<bits\stdc++.h> 
using namespace std; 
int main() 
{ 
    string num; 
    cout << "Input numbers : " << endl; 
    cin >> num; 
    int significantDigits = 0; 
    int zero = 0; 
    for(int i = 0; i < num.size(); i++) 
    { 
        if (num[i] >= '1' && num[i] <= '9') 
        { 
            zero = 1; 
            significantDigits++; 
        } 
        else if (num[i] == '0' && zero) 
        { 
            significantDigits++; 
        } 
        else if (num[i] == '.') 
        { 
            continue; 
        } 
    } 
    cout << "Number of significant digits : " <<  significantDigits << endl; 
}
