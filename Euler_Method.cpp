#include<iostream>
#include<cmath>
using namespace std;

float f(float x,float y){
    return x*cos(x);
}
int main()
{
float xn=5,y;
float h=0.2;
float x0=0;
float y0=1;
while(x0<xn){
   y=y0+h*f(x0,y0);
   cout<<x0<<"                           "<<y0<<endl;
   x0=x0+h;
   y0=y;   
}
return 0;
}