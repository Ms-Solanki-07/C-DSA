#include<iostream>
using namespace std;

int path(int i, int j, int m, int n){
    if(i==m-1 and j==n-1) return 1;
    if(i>= m or j>=n) return 0;
    return path(i, j+1, m, n) + path(i+1, j, m, n);
}

int main() {

    cout<<path(0,0,3,3);

    return 0;
}