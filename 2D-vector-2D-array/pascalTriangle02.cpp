// pascel triangle
// given an integer n, return the first n rows of pascal's triangle

#include<iostream>
#include<vector>
using namespace std;

void pascalTri(int n){
    int a[n][n];
    for(int i=0; i<n; i++){
        // for(int j=0; j<n-i-1; j++){
        //     cout<<" ";
        // }

        for(int j=0; j<=i; j++){
            if(j==0 || i==j){
                a[i][j] = 1; 
            } else {
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<=i; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main () {

    int n;
    cout<<"Enter the value of n :";
    cin>>n;

    pascalTri(n);

    return 0;
}