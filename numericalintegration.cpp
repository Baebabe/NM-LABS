#include <iostream>
using namespace std;

float f(float x)
{
    return 1 / (1 + x * x);
}

void trapezoidal_rule(float xn, float x0, float h, int n)
{
    float sum1 = 0, sum2 = 0;
    sum1 = f(x0) + f(xn);
    for (int i = 1; i < n; i++)
    {
        float k = x0 + i * h;
        sum2 += 2 * f(k);
    }
    float yn = 0.5 * h * (sum1 + sum2);
    cout << "Trapezoidal Rule: " << yn << endl;
}

void simpsons_1by3_rule(float xn, float x0, float h, int n)
{
    float sum1 = 0, sum2 = 0;
    sum1 = f(x0) + f(xn);
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            float k = x0 + i * h;
            sum2 += 2 * f(k);
        }
        else
        {
            float k = x0 + i * h;
            sum2 += 4 * f(k);
        }
    }
    float yn = (h / 3) * (sum1 + sum2);
    cout << "Simpson's 1/3 Rule: " << yn << endl;
}

void simpsons_3by8_rule(float xn, float x0, float h, int n)
{
    float sum1 = 0, sum2 = 0;
    sum1 = f(x0) + f(xn);
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            float k = x0 + i * h;
            sum2 += 2 * f(k);
        }
        else
        {
            float k = x0 + i * h;
            sum2 += 3 * f(k);
        }
    }
    float yn = (3 * h / 8) * (sum1 + sum2);
    cout << "Simpson's 3/8 Rule: " << yn << endl;
}

int main()
{
    float x0, xn;
    int n;
    float h;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of x0 and xn: ";
    cin >> x0 >> xn;
    h = (xn - x0) / n;
    trapezoidal_rule(xn, x0, h, n);
    simpsons_1by3_rule(xn, x0, h, n);
    simpsons_3by8_rule(xn, x0, h, n);
    return 0;
}
