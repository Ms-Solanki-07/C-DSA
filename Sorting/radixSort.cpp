#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int> &v, int pos){
    int n = v.size();
    // creating freq array
    vector<int> freq(10, 0);
    for(int i=0; i<n; i++){
        freq[(v[i]/pos)%10]++;
    }

    // cummulative freq
    for(int i=1; i<10; i++){
        freq[i]+= freq[i-1];
    }

    //ans array
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        ans[--freq[(v[i]/pos)%10]] = v[i];
    }

    for(int i=0; i<n; i++){
        v[i] = ans[i];
    }
}

void radixSort(vector<int> &v){
    int maxEle = INT16_MAX;
    for(auto x:v){
        maxEle = max(x, maxEle);
    }

    for(int pos=1; maxEle/pos > 0; pos *=10){
        countSort(v, pos);
    }
}

int main () {
    vector<int> v = {170, 45, 75, 90, 802, 2};
    
    radixSort(v);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" "; 
    }
    cout<<endl;
    return 0;
}