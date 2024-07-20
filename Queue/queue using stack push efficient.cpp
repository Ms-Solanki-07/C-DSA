#include<iostream>
#include<stack>
using namespace std;
// queue using stack
// push efficient

class Queue{
    stack<int> st;
    
    public:
    Queue() {}
    
    void push(int x) { //enqueue
        st.push(x);
        return;
    }
    
    void pop(){  // dequeue
        if(isEmpty()) return;
        stack<int> temp;
        while(st.size() > 1) {
            temp.push(st.top());
            st.pop();
        }
        st.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    
    bool isEmpty(){
        return st.empty();
    }
    
    int front() {
        stack<int> temp;
        while(st.size() > 1) {
            temp.push(st.top());
            st.pop();
        }
        int res = st.top();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        } 
        return res;
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