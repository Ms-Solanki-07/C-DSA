// pascel triangle
// given an integer n, return the first n rows of pascal's triangle

#include<iostream>
#include<vector>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*fact(n-1);
} 

int main () {

    int n;
    cout<<"Enter the value of n :";
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }

        for(int j=0; j<=i; j++){
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    }

    return 0;
}