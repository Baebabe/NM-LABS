#include<iostream>
#include<cmath>
using namespace std;

float calculate(float x){
    return (sin(x)+x*x*cos(x));
}

float mean(float a, float b){
    return (a + b) / 2;
}

float bisection(float a, float b, float e){
    float c;
    int count=0;
    while(calculate(a)*calculate(b)<0 || count<100){
        c = mean(a, b);
        count++;
        if(abs(calculate(c)) < e){
            return c;
        }

        if(calculate(a) * calculate(c) < 0){
            b = c;
        }
        else {
            a = c;
        }
    }
    if(count>=100){
        cout<<"The function is discountinuous in the interval.";
        exit(0);
    }
    else{
    return c;
    }
}

int main(){
    float a, b, e;
    cout << "Enter the values of a, b, tolerance: " << endl;
    cin >> a >> b >> e ;
    cout << "The root is " << bisection(a, b, e) << endl;
    return 0;
}
