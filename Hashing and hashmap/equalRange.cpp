#include<iostream>
#include<map>
using namespace std;

int main() {
    multimap<int,int> m;

    m.insert({1,1});
    m.insert({2,4});
    m.insert({3,9});
    m.insert({4,16});
    m.insert({4,20});

    auto a = m.equal_range(4);

    for(auto it = a.first; it!=a.second; it++){
        cout<<it->first<<"-"<<it->second<<endl;
        
    }
    
    
    return 0;
}