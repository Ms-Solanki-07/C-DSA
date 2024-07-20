#include<iostream>
using namespace std;

int sum(int *arr, int idx, int n){
    if(idx == n-1){
        return arr[idx];
    }

    return arr[idx]+ sum(arr, idx+1, n);
}
int main () {
    int arr[] = {3,4,1,2,3};
    cout<<sum(arr, 0, 5);

    return 0;
}