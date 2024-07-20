// Check if we can partition the array into two subarrays with equal sum. more formally,
// check that the prefix sum of a part of the array is equal to the sufix sum of rest of the array.


#include<iostream>
#include<vector>
using namespace std;

bool checkPrefixSuffixSum(vector<int> &v){
    int totalSum = 0;
    for(int i=0; i<v.size(); i++){
        totalSum += v[i];
    }

    int prefixSum = 0;
    for(int i=0; i<v.size(); i++){
        prefixSum += v[i];
        int suffixSum = totalSum + prefixSum;

        if(prefixSum == suffixSum){
            return true;
        }
    }
    return false;
}

int main () {

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> v(n);

    cout<<"Enter the element of array : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<"Array : ";
    for(int i=0; i<v.size(); i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<checkPrefixSuffixSum(v);
    return 0;
}