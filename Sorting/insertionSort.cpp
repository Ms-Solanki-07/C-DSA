// repeatedly take element from unsorted subarray & insert in sorted subarray.
 
#include<iostream>
using namespace std;
int main () {
    int arr[] = {3,6,2,1,4,8};
    int n = 6;

    for(int i=1; i<n; i++){
        int curr_ele = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>curr_ele){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=curr_ele;   
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
