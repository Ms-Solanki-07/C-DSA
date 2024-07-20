#include<iostream>
#include<list>
using namespace std;


int main(){
    list<int> list1{4,1,7,9};
    
    auto itr = list1.begin();
    advance(itr, 2); // itr pointing to 3
    
    list1.insert(itr, 5);
    for(auto num : list1){
        cout<<num<<" ";
    } cout<<endl;
    
    list1.insert(itr, 2, 8);  //insert 8 two times before the itr
    for(auto num : list1){
        cout<<num<<" ";
    } cout<<endl;
    
    auto l = list1.begin();
    auto r = list1.begin();
    advance(r, 2); 
    
    list1.insert(itr, l, r); //insert l to r in list before itr
    for(auto num : list1){
        cout<<num<<" ";
    } cout<<endl;
              
    return 0;
}