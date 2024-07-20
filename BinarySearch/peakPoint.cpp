#include<iostream>
#include<vector>
using namespace std;

int peakElementInMountainArray(vector<int> &input){
    int lo = 1;
    int hi = input.size();
    int ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(input[mid]>input[mid-1]){
            // inc curve
            ans = max(mid, ans);
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return ans;
}

int main () {
    vector<int> input = {0,4,2,1};
    cout<<peakElementInMountainArray(input);

    return 0;
}