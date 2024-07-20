// given an integers aaray a , return the prefix sum/running sum in the same array without creating a new array

#include<iostream>
#include<vector>
using namespace std;

void sumRunning(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        v[i] += v[i-1];
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}

int main() {

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

    sumRunning(v);

    return 0;
}