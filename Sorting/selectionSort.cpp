// Repeatedly find min element in unsorted array & place it at beginning of unsorted array

#include<iostream>
using namespace std;
int main() {
    int arr[] = {30,20,40,10,60,50};
    int n = 6;

    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }

        if(arr[minIdx] != arr[i]){
            swap(arr[minIdx], arr[i]);
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}