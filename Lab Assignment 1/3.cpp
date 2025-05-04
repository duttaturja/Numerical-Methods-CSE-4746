#include<bits/stdc++.h> 
using namespace std; 
int horners(vector<int> nums, int x) 
{ 
    int sz = nums.size(); 
    int res = nums[0]; 
    for(int i = 1; i < sz; i++) 
    { 
        res = res * x + nums[i]; 
    }
    return res; 
} 
int main() 
{ 
    //f(x) = x^3 - 2x^2 + 5x + 10 for x = 5 
    vector<int> coefficients = {1, -2, 5, 10}; 
    int x = 5; 
    cout << "Value of polynomial using horner's is : " << horners(coefficients, x) << endl; 
} 
