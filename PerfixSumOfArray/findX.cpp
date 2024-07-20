#include<iostream>
using namespace std;

bool find(int *arr, int n, int i, int x){
    if(i==n){
        // cout<<"not found"<<endl;
        return false;
    }
    if(arr[i]==x){
        // cout<<"x found"<<endl;
        return true;
    } else {
        find(arr, n, i+1, x);
    }
}

int main () {
    int arr[]={2,3,1,9,4,5,6};
    int n = 7;
    int x = 7;
    if(find(arr, n, 0, x)) cout<<"found";
    else cout<<"not found";
}