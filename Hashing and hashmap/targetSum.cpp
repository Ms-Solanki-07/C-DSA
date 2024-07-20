#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> targetSumPair(vector<int> v, int targetSum){

    unordered_map<int, int> m;
    vector<int> ans(2, -1);

    for(int i=0; i<v.size(); i++){
        if(m.find(targetSum-v[i]) != m.end()){
            ans[0] = m[targetSum-v[i]];
            ans[1] = i;
            return ans;
        } else {
            m[v[i]] = i;
        }
    }
}

int main() {

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int targetSum;
    cin>>targetSum;

    vector<int> ans = targetSumPair(v, targetSum);

    cout<<ans[0]<<", "<<ans[1]<<endl;

    return 0;
}