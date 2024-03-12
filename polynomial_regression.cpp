#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float x[100], y[100];
    int d, n;
    cout << "Enter the no of data: " << endl;
    cin >> n;
    cout << "Enter the degree of the polynomial: " << endl;
    cin >> d;

    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] : ";
        cin >> x[i];
        cout << "y[" << i << "] : ";
        cin >> y[i];
    }

    float M[100][100];
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d; j++) {  
            float sum = 0;
            for (int k = 0; k < n; k++) {
                sum += pow(x[k], i + j);
            }
            M[i][j] = sum;
        }
        M[i][d + 1] = 0; 
        for (int k = 0; k < n; k++) {
            M[i][d + 1] += pow(x[k], i) * y[k];
        }
    }
cout<<endl;
    for (int i = 0; i <= d; i++) {
        for (int j = 0; j <= d + 1; j++) {
            cout << "M["  << i << "][" << j << "] : ";
            cout << M[i][j] << endl;
        }
    }
    for(int i=0;i<=d;i++)
     {
          for(int j=0;j<=d;j++)
          {
               if(i!=j)
               {
                     float ratio = M[j][i]/M[i][i];
                    for(int k=0;k<=d+1;k++)
                    {
                        M[j][k] = M[j][k] - ratio*M[i][k];
                    }
               }
          }
     }
          float a[10];
     for(int i=0;i<=d;i++)
     {
        a[i] = M[i][d+1]/M[i][i];
     }

	 cout<< endl<<"Solution: "<< endl;

	 for(int i=0;i<=d;i++)
	 {
	  	cout<<"a["<< i<<"] = "<< a[i]<< endl;
	 }

    return 0;
}
