#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &input, int x, int lo, int hi){
        if(lo>hi) return -1;

        int mid = lo+ (hi-lo)/2;
        if(input[mid]==x) return mid;
        else if(input[mid]<x){
            binarySearch(input, x, mid+1, hi);
        } else if(input[mid]>x) {
            binarySearch(input, x, lo,  mid-1);
        }
    
    
}

int main () {
    vector<int> input = {3,4,5,7,9,10,14};  // sorted array
    int x=10;

    cout<<binarySearch(input, x, 0, input.size()-1);

    return 0;

}