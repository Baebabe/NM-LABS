#include<iostream>
using namespace std;

int main() {
    float a[10][10], x[10];
    int n;

    cout << "Enter the number of unknowns: ";
    cin >> n;

    cout << "Enter the augmented matrix coefficients:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Gaussian Elimination
    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0.0) {
            cout << "error: Division by zero!" << endl;
            break;
        }
        for (int j = i+1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}

/*
a[1]1]= 1
a[1]2]= 1
a[1]3]= 1
a[1]4]= 9
a[2]1]= 2
a[2]2]= -3
a[2]3]= 4
a[2]4]= 13
a[3]1]= 3
a[3]2]= 4
a[3]3]= 5
a[3]4]= 40
*/