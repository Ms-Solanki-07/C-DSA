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

vector<int> prevGreaterElement(vector<int> &arr){
    int n = arr.size();
    reverse(arr.begin(), arr.end());
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
    reverse(arr.begin(), arr.end());
    reverse(output.begin(), output.end());
    return output;
}

vector<int> nextSmallerElement(vector<int> &arr){
    int n = arr.size();
    vector<int> output (n, -1);
    stack<int> idxStack;
    idxStack.push(0);
    for(int i=1; i<n; i++){
        while(!idxStack.empty() && arr[i] < arr[idxStack.top()]){
            output[idxStack.top()] = arr[i];
            idxStack.pop();
        }
        idxStack.push(i);
    }
    return output;
}

vector<int> prevSmallerElement(vector<int> &arr){
    int n = arr.size();
    reverse(arr.begin(), arr.end());
    vector<int> output (n, -1);
    stack<int> idxStack;
    idxStack.push(0);
    for(int i=1; i<n; i++){
        while(!idxStack.empty() && arr[i] < arr[idxStack.top()]){
            output[idxStack.top()] = arr[i];
            idxStack.pop();
        }
        idxStack.push(i);
    }
    reverse(arr.begin(), arr.end());
    reverse(output.begin(), output.end());
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
    output = prevSmallerElement(arr);
    
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<output[i]<<" ";
    } cout<<endl;
    
    return 0;
}