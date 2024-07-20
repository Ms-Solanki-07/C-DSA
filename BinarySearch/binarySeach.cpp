#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &input, int x){
    int lo = 0;  //start of the search space
    int hi = input.size()-1;

    while(lo<hi){
        int mid = lo+ (hi-lo)/2;   // mid = (lo+hi)/2 -> overflow
        if(input[mid]==x) return mid;
        else if(input[mid]<x){
            lo = mid+1;
        } else {
            hi= mid-1;
        }
    }
    return -1;
}

int main () {
    vector<int> input = {3,4,5,7,9,10,14};  // sorted array
    int x=10;

    cout<<binarySearch(input, x);

    return 0;

}