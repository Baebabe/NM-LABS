#include<iostream>
using namespace std;
int main()
{
 float  x[10],y[10];
 int n;
 cout << "Enter the no of data: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] : ";
        cin >> x[i];
        cout << "y[" << i << "] : ";
        cin >> y[i];
    }
    float xn;
    cout<<"Enter the final value of x : "<<endl;
    cin>>xn;
    float sum=0;
    for(int i=0;i<n;i++){
        float product =1;
        for(int j=0;j<n;j++){
           if(i!=j)
           {
            product*=((xn-x[j])/(x[i]-x[j]));
           }
           else{
            continue;
           }
        }
        sum+=y[i]*product;
    }
    cout<<"y(x)="<<sum;
return 0;
}