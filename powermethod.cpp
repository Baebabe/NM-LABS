/*
Algorithm
Get the order of the matrix (n) and its coefficients.
Input the initial guess vector (x).

Repeat the following steps until the difference between
 the current and previous eigenvalues is less than 0.00001:
a. Initialize the intermediate vector y to zero.
b. Compute the product of the matrix a and the current 
vector x and store it in the vector y.
c. Update the current vector x with the 
values from the intermediate vector y.
d. Store the current eigenvalue in the
 temporary variable temp.
e. Set the eigenvalue lambda to 1.
f. Find the element with the maximum absolute value 
in the updated vector x and assign it to lambda.
g. Normalize the vector x by dividing each element by the eigenvalue lambda.
*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a[10][10], x[10], y[10], lambda = 1, temp;
    int n, i, j;

    cout << "Enter the order of matrix : ";
    cin >> n;
    cout << "Enter Coefficient of Matrix: " << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "Enter Initial Guess Vector: " << endl;

    for (i = 0; i < n; i++)
        cin >> x[i];

    do
    {
        for (i = 0; i < n; i++)
        {
            y[i] = 0;
            for (j = 0; j < n; j++)
                y[i] += a[i][j] * x[j];
        }
        for (i = 0; i < n; i++)
        {
            x[i] = y[i];
        }
        temp = lambda;
        lambda = 1;
        for (i = 0; i < n; i++)
        {
            if (fabs(x[i]) > fabs(lambda))
                lambda = x[i];
        }
        for (i = 0; i < n; i++)
            x[i] /= lambda;

    } while (fabs(lambda - temp) > 0.00001);

    cout << "Eigenvalue is : " << lambda << endl;

    cout << "Eigenvector is: ";
    for (i = 0; i < n; i++)
        cout << endl
             << x[i];

    return 0;
}
