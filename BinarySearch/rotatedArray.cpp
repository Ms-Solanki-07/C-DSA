/*
a rotated sorted array, array is sorted array on which rotation opreation has been 
performed some number of times, given a roated sorted array. find the index of the minimum
element in the array. follow 0 based indexing.
it is guranted that all the elements in the array are unique.
*/

#include<iostream>
#include<vector>
using namespace std;

int findMinInSortedRotated(vector<int> &input){   // time complexity - O(logN)
    
    if(input.size() == 1) return input[0];
    int lo = 0;
    int hi = input.size()-1;

    if(input[lo] < input[hi]){  // array is only sorted
        return lo;
    }

    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(input[mid]>input[mid+1]) return mid+1;
        if(input[mid]< input[mid-1]) return mid;

        if(input[mid]>input[lo]){
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return -1;
}

int main (){
    
    int n, target;
    cout<<"size of vector";
    cin>>n;
    vector<int> input;


    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        input.push_back(x);
    }

    

    cout<<findMinInSortedRotated(input);

    return 0;
}