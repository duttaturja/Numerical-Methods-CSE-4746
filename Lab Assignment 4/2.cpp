#include <iostream>
using namespace std;

int main() {
    float x[] = {2, 4, 6, 8};
    float y[] = {1.4, 2.0, 2.4, 2.8};
    int n = 4;

    float sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    float sumY = 0, sumXY = 0, sumX2Y = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i]*x[i];
        sumX3 += x[i]*x[i]*x[i];
        sumX4 += x[i]*x[i]*x[i]*x[i];
        sumY += y[i];
        sumXY += x[i]*y[i];
        sumX2Y += x[i]*x[i]*y[i];
    }

    float A[3][4] = {
        {n, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}
    };

    // Gauss Elimination
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            float ratio = A[j][i]/A[i][i];
            for (int k = 0; k < 4; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    float c = A[2][3] / A[2][2];
    float b = (A[1][3] - A[1][2]*c) / A[1][1];
    float a = (A[0][3] - A[0][1]*b - A[0][2]*c) / A[0][0];

    cout << "The best fit parabola is: y = " << a << " + " << b << "x + " << c << "x^2" << endl;
    return 0;
}
