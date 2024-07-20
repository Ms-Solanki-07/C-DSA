#include<iostream>
#include<stack>
using namespace std;
// queue using stack
// pop efficient

class Queue{
    stack<int> st;
    
    public:
    Queue() {}
    
    void push(int x) { //enqueue time: O(n)
        stack<int> temp;
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return;
    }
    
       void pop(){  // dequeue  time O(1);
        if(st.empty()) return;
        st.pop();
    }
    
    bool isEmpty(){
        return st.empty();
    }
    
    int front() {
        return st.top();
    }
    
};




int main() {
    Queue q;
    q.push(8);
    q.push(6);
    q.push(5);
    q.push(7);
    
    q.pop();
    
    
        cout<<"queue: ";
        while(!q.isEmpty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;


    return 0;
}