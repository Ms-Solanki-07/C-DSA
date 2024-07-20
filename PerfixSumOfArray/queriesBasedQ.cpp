// Given an array of integers of size n, answer q queries where you need to print the sum of values in a given
// range of indices from l to r(both included)
// the values of l and r in queries allow 1-based indexing

#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> v(n+1, 0);

    cout<<"Enter the element of array : ";
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    cout<<"Array : ";
    for(int i=0; i<v.size(); i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;

    // calculate of prefix sum array
    for(int i=1; i<=n; i++){
        v[i] += v[i-1];
    }
    cout<<"prefix array : ";
    for(int i=0; i<v.size(); i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;

    int q;
    cout<<"Enter the number of queies :";
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;

        int ans = 0;
        // ans = prefixsumarray[r] - prefixsumarray[l-1];
        ans = v[r]-v[l-1];

        cout<<"ans :"<<ans<<endl;
    }

    return 0;
}