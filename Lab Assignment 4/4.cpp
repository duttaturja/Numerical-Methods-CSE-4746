#include <iostream>
using namespace std;

float f(float x, float y) {
    return x*x*x + y;
}

int main() {
    float x = 0, y = 1, h = 0.01;

    for (int i = 0; i < 2; i++) {
        y = y + h * f(x, y);
        x = x + h;
    }

    cout << "Value of y at x = 0.02 is: " << y << endl;
    return 0;
}
