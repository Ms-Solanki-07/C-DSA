#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int> q;
    stack<int> st;
    q.push(4);  //enqueue
    q.push(6);
    q.push(8);
    q.push(10);
    q.push(12);

    /*cout<<"queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }    
    cout<<endl; */
    
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    cout<<"reverse queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }    
    cout<<endl;
        

    return 0;
}