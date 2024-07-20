#include<iostream>
#include<vector>
#include<deque>
using namespace std;

// k is size of saliding window
vector<int> maxSalidingWindow(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> res;
    
    for(int i=0; i<k; i++){
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    
    for(int i=k; i<arr.size(); i++){
        int curr = arr[i];
        if(dq.front() == (i-k) ){
            dq.pop_front();
        }    
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    return res;
}

int main(){

    vector<int> arr = {3,4,5,2,7,1,2};
    int k = 3;
    vector<int> result;
    
    cout<<"array: ";
    for(auto i: arr){
        cout<<i<<" ";
    } cout<<endl;
    
    
    result = maxSalidingWindow(arr, k);
    
    cout<<"sidling window Max: ";
    for(auto i: result){
        cout<<i<<" ";
    } cout<<endl;
    
    return 0;
}