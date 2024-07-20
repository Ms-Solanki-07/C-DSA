/*
given an integer array arr, move all 0's to the end of it while maintaining the relative order of the non zero elements
Note- that you must do this in place without making a copy of the array.
*/


#include<iostream>
#include<vector>
using namespace std;
int main(){

    int arr[]={1,0,2,0,0,5};
    int n=6;

    for(int i=0; i<n-1; i++){
        bool flag = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]<arr[j+1] && arr[j]==0){
                swap(arr[j], arr[j+1]);
                flag=true;
            }
        }
        if(!flag){
            break;
        }

    }

    // for(int i=n-1; i>=0; i--){
    //     int j=0; 
    //     bool flag= false;
    //     while(j != i){
    //         if(arr[j]==0 && arr[j+1] != 0){
    //             swap(arr[j], arr[j+1]);
    //             flag=true;
    //         }
    //         j++;
    //     }
    //     if(!flag){
    //         break;
    //     }
    // }
    
    // time complexity- O(n^n)


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}