#include<iostream>
#include<cmath>
using namespace std;

float f(float x,float y){
    return sin(x)+cos(y);
}
int main()
{
float xn=0.6,y1,y2;
float h=0.2;
float x0=0;
float y0=1;
while(x0<xn){
float slope=f(x0,y0);
y1=y0+slope*h;
float slope1=f(x0,y1);
float slope_avg=(slope1+slope)/2.0;
y2=y0+slope_avg*h;
   cout<<x0<<"                           "<<y0<<endl;
x0=x0+h;
y0=y2;  
}
return 0;
}