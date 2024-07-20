#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq;
    
    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(8);
    dq.push_back(9);
    dq.push_back(4);
    dq.push_front(9);
    dq.pop_back();
    
    
    cout<<"Deque: ";    
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();    
    } cout<<endl;
    
    cout<<dq.back()<<endl;
    return 0;
}