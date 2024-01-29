#include <iostream>
#include <cmath>
using namespace std;

float calculate(float x)
{
    return (2*x*x*sin(x)+cos(x));
}

float derivative(float x)
{
    return 4*x*sin(x)-sin(x)+2*x*x*cos(x);
}
float newton_raphson(float a, float e)
{
    float root;
    int count=0;
    do
    {
        if(derivative(a)==0){
            cout<<"The derivative is zero"<<endl;
            exit(0);
        }
        root = a - calculate(a) / derivative(a);
        count++;
    } while (fabs(root - a) <= e || count<100);
    return root;
}
int main()
{
    float n_root, e;
    cout << "Enter nearby root and value of e:" << endl;
    cin >> n_root >> e;
    cout << "The exact root is " << newton_raphson(n_root, e);
    return 0;
}