#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> input(n);

    for(int i=0; i<n; i++){
        cin>>input[i];
    }

    map<int,int> m;

    for(int i=0; i<n; i++){
        //storing frequency of every element of input array
        m[input[i]]++;
    }

    int sum = 0;
    for(auto pair: m){  //pair-> ele, freq
        if(pair.second>1){
            sum+=pair.first;
        }
    }

    cout<<"ans: "<<sum<<endl;

    return 0;
}