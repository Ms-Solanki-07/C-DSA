#include<iostream>
#include<list>
using namespace std;


int main(){
    list<int> list1{1,2,3,4};
    
    auto itr = list1.begin();
    
    //travesal of list
    //using range based loop
    for(auto num : list1){
        cout<<num<<" ";
    } cout<<endl;
    
    //using iterators
    for(auto itr = list1.begin(); itr != list1.end(); itr++){
        cout<<*itr<<" ";
    } cout<<endl;
    
    //revrese travesal
    for(auto itr = list1.rbegin(); itr != list1.rend(); itr++){
        cout<<*itr<<" ";
    } cout<<endl;
           
    return 0;
}