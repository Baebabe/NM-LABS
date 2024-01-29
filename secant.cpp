#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
    return x * sin(x) + cos(x);
}

float secant(float a, float b, float e)
{
    float c;
    do
    {
        c = b - (f(b) * (a - b)) / (f(a) - f(b));
        a = b;
        b = c;
    } while (fabs(f(c)) > e); 
    return c;
}

int main()
{
    float a, b, e;
    cout << "Enter the two initial values a and b and the tolerance e :" << endl;
    cin >> a >> b >> e;
    cout << "The required root is " << secant(a, b, e) << endl;
    return 0;
}
