// given two sorted arrays, write a program to merge them in a sorted manner.

#include<iostream>
using namespace std;
int main (){
    int arr1[] = {1,3,5,8,10};
    int arr2[] = {2,7,8};
    int s1=sizeof(arr1)/sizeof(arr1[0]);
    int s2=sizeof(arr2)/sizeof(arr1[0]);

    int arr3[s1+s2];

    int i=0;
    int j=0;
    int k=0;

    while(i<s1 && j<s2){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        } else {
            arr3[k++]=arr2[j++];
        }
    }

    while(i<s1){
        arr3[k++]=arr1[i++];
    }
    while(j<s2){
        arr3[k++]=arr2[j++];
    }

    for(int i=0; i<s1+s2; i++){
        cout<<arr3[i]<<" ";
    } cout<<endl;


}