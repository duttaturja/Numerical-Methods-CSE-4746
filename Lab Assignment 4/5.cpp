#include <iostream>
using namespace std;

float f(float x, float y) {
    return x + y;
}

int main() {
    float x = 0, y = 1, h = 0.1;

    for (int i = 0; i < 2; i++) {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h/2, y + k1/2);
        float k3 = h * f(x + h/2, y + k2/2);
        float k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x + h;

        cout << "y(" << x << ") = " << y << endl;
    }

    return 0;
}
