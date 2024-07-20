#include<iostream>
#include<vector>
using namespace std;

void countSort(int arr[],int n){

    //finding max element
    int maxEle = INT16_MAX;
    for(int i=0; i<n; i++){
        maxEle = max(arr[i], maxEle);
    }

    // create the frequency array
    vector<int> freq(maxEle+1, 0);
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    // calculate cummlative frequency
    for(int i=1; i<=maxEle; i++){
        freq[i] += freq[i-1];
    }


    //calculate the sorted array
    int ans[n];
    for(int i=n-1; i>=0; i--){
        ans[--freq[arr[i]]] = arr[i];
    }

    //copy back the ans to original array
    for(int i=0; i<n; i++){
        arr[i]= ans[i];
    }

}

int main () {
    int arr[]= {30,10,30,20,40,70};
    int n=6;

    countSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}