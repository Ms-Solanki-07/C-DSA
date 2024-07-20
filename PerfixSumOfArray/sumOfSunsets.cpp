/*
given an array of integers, print sums of all subsets in it. 
outputs sums can be printed in any order
*/

#include<iostream>
#include<vector>
using namespace std;
void sumofSubset(int *arr, int n, int i, int sum, vector<int> &result){
    if(i == n){
        result.push_back(sum);
        return;
    }
    sumofSubset(arr, n, i+1, sum + arr[i], result);
    sumofSubset(arr, n, i+1, sum, result);
}


int main () {
    int arr[] = {2,4,5};
    int n=3;
    vector<int> result;
    sumofSubset (arr, n, 0, 0, result);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}