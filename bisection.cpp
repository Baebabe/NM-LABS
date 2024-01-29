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
// void insertitem(Node * &head,int coeff, int exp){
//     Node *node1=new Node(coeff,exp);
//     if(head==NULL || exp > head->exponent){
//         node1->next=head;
//         head=node1;
//     }
//     else{
//         Node *temp=head;
//         while(temp->next!=NULL && temp->next->exponent>exp){
//            temp=temp->next;
//         }
//         node1->next=temp->next;
//         temp->next=node1;
//     }
// }

// void displaypolynomial(Node *poly){
//     while(poly!=NULL){
//         cout<<poly->coefficient<<"x^"<<poly->exponent;
//         poly=poly->next;
//         if(poly!=NULL){
//             cout<<"+";
//         }
//     }
//     cout<<endl;
// }
// int main()
// {
//  Node*p1=NULL;
//  Node*p2=NULL;
//  insertitem(p1,3,5);
//  insertitem(p1,3,4);
//  displaypolynomial(addpolynomial(p1,p2));
// return 0;
// }