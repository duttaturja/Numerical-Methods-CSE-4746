#include<bits/stdc++.h> 
using namespace std; 
double round_off(double N, double n) 
{ 
	int h; 
	double l, a, b, c, d, e, i, j, m, f, g; 
	b = N; 
	c = floor(N); 
	for (i = 0; b >= 1; ++i) 
		b = b / 10;
		
	d = n - i; 
	b = N; 
	b = b * pow(10, d); 
	e = b + 0.5; 
	
	if ((float)e == (float)ceil(b))
	{ 
		f = (ceil(b)); 
		h = f - 2; 
		if (h % 2 != 0)
		{ 
			e = e - 1; 
		} 
	} 
	j = floor(e); 
	m = pow(10, d); 
	j = j / m; 
	return j; 
} 
int main() 
{ 
	double num; 
	cout << "Enter number : " << endl; 
	cin >> num; 
	int decimalCount; 
	cout << "Enter decimal precision : " << endl; 
	cin >> decimalCount; 
	cout << "Rounded output : " << endl; 
	cout << round_off(num, decimalCount) << endl; 
}
