// pascel triangle
// given an integer n, return the first n rows of pascal's triangle

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> pascaltri(int n){
    vector<vector<int>> pascal(n);

    for(int i=0; i<n; i++){
       pascal[i].resize(i+1);

    
        for(int j=0; j<i+1; j++){
            if(j==0 || i==j){
                pascal[i][j]=1;
            } else {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
    return pascal;

    
}

int main () {

    int n;
    cout<<"Enter the value of n :";
    cin>>n;

    vector<vector<int>> ans;
    ans = pascaltri(n);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans.size()-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}