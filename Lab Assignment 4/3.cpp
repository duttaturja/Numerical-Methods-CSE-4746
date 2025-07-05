#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x[] = {2, 10, 26, 61};
    float y[] = {600, 500, 400, 350};
    int n = 4;

    float sumX = 0, sumLogY = 0, sumX2 = 0, sumXLogY = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumLogY += log(y[i]);
        sumX2 += x[i]*x[i];
        sumXLogY += x[i] * log(y[i]);
    }

    float b = (n * sumXLogY - sumX * sumLogY) / (n * sumX2 - sumX * sumX);
    float A = (sumLogY - b * sumX) / n;
    float a = exp(A);

    cout << "Best fit exponential curve: y = " << a << " * e^(" << b << "x)" << endl;
    return 0;
}
