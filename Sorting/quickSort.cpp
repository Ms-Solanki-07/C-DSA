
#include<iostream>
using namespace std; 

int partication(int arr[], int first, int last){

    int pivot = arr[last];
    int i=first-1; //for inserting elements less then pivot
    for(int j=first; j<last; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    //now i is pointing to the last element < pivot
    // correct position for pivot will be i+1

    swap(arr[i+1], arr[last]);
    return i+1;
}

void quickSort(int arr[], int first, int last){
    if(first>=last) return;
    int pi = partication(arr, first, last);
    quickSort(arr, 0, pi-1);
    quickSort(arr, pi+1, last);
}

int main () {

    int arr[] = {18,12,30,16,35,20};
    int n = 6;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}