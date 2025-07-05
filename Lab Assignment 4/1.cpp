#include <iostream>
using namespace std;

int main() {
    int x[] = {-2, -1, 0, 1, 2};
    int y[] = {1, 2, 3, 4, 5};
    int n = 5;

    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    float b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float a = (sumY - b * sumX) / n;

    cout << "The best fit line is: y = " << a << " + " << b << "x" << endl;
    return 0;
}
