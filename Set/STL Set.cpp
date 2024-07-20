#include<iostream>
#include<set>
using namespace std;


int main(){
    set<int> s;
    
    s.insert(4);
    s.insert(6);
    s.insert(2);
    s.insert(4);
    s.insert(9);
    s.insert(3);
    s.insert(5);
    
    //traversal and print
    set<int> :: iterator itr;
    for(itr = s.begin(); itr != s.end(); itr++){
        cout<<*itr<<" ";
    } cout<<endl;
    
    
    //delete by value    
    //s.erase(3); //value

//    for(itr = s.begin(); itr != s.end(); itr++){
  //      cout<<*itr<<" ";
    //} cout<<endl;    

    //delet by position
    //auto i = s.begin();
    //advance(i, 3); //itr = 4th positon
    
    //s.erase(i); //positon
    
    
    //delete in range
    auto sPos = s.begin();
    auto ePos = s.begin();
    advance(ePos, 2); //epos = 3rd positon
    
    s.erase(sPos, ePos);
    
    //print
    for(itr = s.begin(); itr != s.end(); itr++){
       cout<<*itr<<" ";
    } cout<<endl;    
    
    //cout<<"size: "<<s.size()<<endl;
    //cout<<"max size: "<<s.max_size()<<endl;
    
    //find/search the value
    if(s.find(10) != s.end()){
        cout<<"value is present"<<endl;
    } else {
        cout<<"value is not present"<<endl;
    }
}