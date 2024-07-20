#include<iostream>
#include<set>

using namespace std;

int main() {
    set<int> s;
    
    int n, p, q;
    cin>>n>>p>>q;
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            
            int correct = i;
            int incorrect = j;
            int unAttend = n-(i+j);
            
            if(unAttend >=0){
                int score = p*correct + q*incorrect;
                s.insert(score);
            } else {
                break;
            }
        }
    }
    
    for(auto itr : s){
        cout<<itr<<" ";
    } cout<<endl;
    
    cout<<"ans: "<<s.size()<<endl;

    return 0;
}