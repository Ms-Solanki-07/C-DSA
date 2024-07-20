#include<iostream>
#include<vector>
using namespace std;
int main () {
    vector<int> v = {20,30,15,40,25};

    for(int i=0; i<v.size()-1; i++){
        for(int j=0; j<v.size()-1-i; j++){
            if(v[j]>v[j+1]){
                int temp = v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}