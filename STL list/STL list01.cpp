#include<iostream>
#include<list>
using namespace std;


int main(){
    list<int> list1{1,2,3,4};
    
    //list<int> :: iterator itr;
    auto itr = list1.begin();
    //itr = list1.end();
    
    cout<<*itr<<endl;
    advance(itr, 2); // iterate the iterator by two position
    cout<<*itr<<endl;
    
    auto revItr = list1.rbegin();
    revItr = list1.rend();
    
    cout<<*revItr<<endl; 
    
        
    return 0;
}