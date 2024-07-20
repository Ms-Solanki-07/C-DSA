#include<iostream>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int idx = size;
        arr[idx] = val;

        while(idx > 1){
            int parentidx = idx/2;

            if(arr[parentidx] < arr[idx]){
                swap(arr[parentidx], arr[idx]);
                idx = parentidx;
            } else {
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        } 
        cout<<endl;
    }

    void deleteformHeap(){
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftIdx = i*2;
            int rightIdx = i*2+1;

            if(leftIdx < size && arr[i] < arr[leftIdx]){
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }
            else if(rightIdx < size && arr[i] < arr[rightIdx]){
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }
            else {
                return ;
            }
        }
    }
};

void Heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }

    return;
}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
    
        Heapify(arr, size, 1);
    }
    return;
}

int main (){
    Heap h;
    h.insert(44);
    h.insert(55);
    h.insert(23);
    h.insert(65);
    h.insert(54);
    h.insert(26);

    h.print();

    h.deleteformHeap();
    h.print();

    int arr[6] = {-1, 54,53,55,52,50};
    int n = 5;

    for(int i=n/2; i>0; i--){
        Heapify(arr, n, i);
    }
    cout<<"after heapify: ";
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);
    cout<<"after sort: ";
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}