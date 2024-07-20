#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    
    vector<int> v1(n);
    vector<int> v2(m);
    
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    
    for(int i=0; i<m; i++){
        cin>>v2[i];
    }
    
     for(int i=0; i<n; i++){
        cout<<v1[i]<<" ";
    } cout<<endl;
    
    for(int i=0; i<m; i++){
        cout<<v2[i]<<" ";
    } cout<<endl;

    
    int ansSum = 0;
    
    set<int> s;
    for(auto ele: v1){
        s.insert(ele);
    }
    
    for(auto ele: v2){
        if(s.find(ele) != s.end()){    
            ansSum += ele;
        }
    }
    
    cout<<"Sum: "<<ansSum<<endl;


    return 0;
}