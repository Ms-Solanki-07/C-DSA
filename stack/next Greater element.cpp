#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    int n = arr.size();
    vector<int> output (n, -1);
    stack<int> idxStack;
    idxStack.push(0);
    for(int i=1; i<n; i++){
        while(!idxStack.empty() && arr[i] > arr[idxStack.top()]){
            output[idxStack.top()] = arr[i];
            idxStack.pop();
        }
        idxStack.push(i);
    }
    return output;
}

int main(){
    cout<<"size of vector:";
    int n;
    cin>>n;
    cout<<"vector element: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<int> output(n);
    output = nextGreaterElement(arr);
    
    cout<<"next greater element vector: "<<endl;
    for(int i=0; i<n; i++){
        cout<<output[i]<<" ";
    } cout<<endl;
    
    return 0;
}