#include<iostream>
#include<list>
using namespace std;


int main(){
    list<int> list1{1,2,3,4,5,6};
    
    auto itr = list1.begin();
    advance(itr, 2); // itr pointing to 3
    
    //delete the element of list
    list1.erase(itr); //delete the element pointed to by the itr
    for(auto num : list1){
        cout<<num<<" ";
    } cout<<endl;
    
    auto str_itr = list1.begin();
    advance(str_itr, 2); // str_itr pointing to 3th element
    auto end_itr = list1.begin();
    advance(end_itr, 4); // end_itr pointing to 5th element
    
    list1.erase(str_itr, end_itr); //delete the element str_itr(including) to end_itr(excluding)
    for(auto num : list1){
        cout<<num<<" ";
    } cout<<endl;
             
              
    return 0;
}