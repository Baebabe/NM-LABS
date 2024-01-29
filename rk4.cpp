#include<iostream>
#include<cmath>
using namespace std;

float f(float x, float y){
    return x*cos(x);

}
int main()
{
    float x1=5,y1;
    float h=0.2;
    float x0=0,y0=1;
    float k1,k2,k3,k4,k;
    while(x0<x1){
    k1=h*f(x0,y0);
    k2=h*f(x0+h/2,y0+k1/2);
    k3=h*f(x0+h/2,y0+k2/2);
    k4=h*f(x0+h,y0+k3);
    k=(k1+2*k2+2*k3+k4)/6;
     cout<<x0<<"                           "<<y0<<endl;
    y1=y0+k;
    x0=x0+h;
    y0=y1;
    }
return 0;
}