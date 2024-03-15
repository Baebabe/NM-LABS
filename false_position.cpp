#include <iostream>
#include <cmath>
using namespace std;

float f(float x) {
    return (cos(x) - x * exp(x));
}
float false_position(float a, float b, float e) {
    float c;
    do {

        c = b - (f(b) * (a - b)) / (f(a) - f(b));
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    } while (fabs(f(c)) > e);
    return c;
}

int main() {
    float a, b, e;
    cout << "Enter the two initial values a and b and the tolerance e :" << endl;
    cin >> a >> b >> e;

    if (f(a) * f(b) >= 0) {
        cout << "The initial values do not bracket the root." << endl;
        return 1; 
    }

    cout << "The required root is " << false_position(a, b, e) << endl;
    return 0;
}
