#include<iostream>
using namespace std;

int maxValue(int *arr, int idx, int n){
    if(idx == n-1){
        return arr[idx];
    }

    return max(arr[idx], maxValue(arr, idx+1, n));
}
int main () {
    int arr[] = {3,4,1,2,3,5,67};
    cout<<maxValue(arr, 0, 7);

    return 0;
}