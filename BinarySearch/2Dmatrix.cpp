#include<iostream>
#include<vector>
using namespace std;

bool searchElementInMatrix(vector<vector<int>> &a, int target){
    int m = a.size();   // no of rows
    int n = a[0].size();  // no of colums
    int lo = 0;
    int hi = m*n-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        int x = mid/m;  
        int y = mid%m;
        if(a[x][y] == target){
            return true;
        } else if(a[x][y] < target) {
            lo = mid +1;
        } else {
            hi = mid-1;
        }
    }
    return false;
}



int main () {
    vector<vector<int>> a = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target = 21;
    cout<<searchElementInMatrix(a, target)<<"\n";

    return 0;
}