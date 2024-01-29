#include<iostream>
#include<cmath>
using namespace std;

float f(float x, float y,float z){
    return z;
}

float g(float x, float y,float z){
    return x+2*y+z;
}

int main()
{
    float x1=3;
    float h=1;
    float x0=1,y0=2,z0=3;
    float k1,k2,k3,k4,k,l1,l2,l3,l4,l;
    while(x0<=x1){
    k1=h*f(x0,y0,z0);
    l1=h*g(x0,y0,z0);
    k2=h*f(x0+h/2,y0+k1/2,z0+l1/2); 
    l2=h*g(x0+h/2,y0+k1/2,z0+l1/2);
    k3=h*f(x0+h/2,y0+k2/2,z0+l2/2);
    l3=h*g(x0+h/2,y0+k2/2,z0+l2/2);
    k4=h*f(x0+h,y0+k3,z0+l3);
    l4=h*f(x0+h,y0+k3,z0+l3);
    k=(k1+2*k2+2*k3+k4)/6;
    l=(l1+2*l2+3*l3+l4)/6;
     cout<<x0<<"         "<<y0<<"                "<<z0<<endl;
    y0=y0+k;
    x0=x0+h;
    z0=z0+l;
    }
return 0;
}