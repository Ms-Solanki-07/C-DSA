#include<iostream>
#include<queue>
using namespace std;
// stack using queue
// push efficient

class stack{
    queue<int> qe;
    
    public:
    stack() {}
    
    void push(int x) { //enqueue time: O(1)
        qe.push(x);
        return;
    }
    
    void pop(){  // dequeue  time O(n);
        if(qe.empty()) return;
        queue<int> temp;
        while(qe.size() > 1){
            temp.push(qe.front());
            qe.pop();
        }
        qe.pop();
        while(!temp.empty()){
            qe.push(temp.front());
            temp.pop();
        }
    }
    
    int top(){    // dequeue  time O(n);
        if(qe.empty()) return 0;
        queue<int> temp;
        while(qe.size() > 1){
            temp.push(qe.front());
            qe.pop();
        }
        int res = qe.front();
        temp.push(qe.front());
        qe.pop();
        while(!temp.empty()){
            qe.push(temp.front());
            temp.pop();
        }
        return res;
    }
    
    bool isEmpty(){
        return qe.empty();
    }
    
};




int main() {
    stack st;
    st.push(8);
    st.push(6);
    st.push(5);
    st.push(7);
    
    st.pop();
    
    
        cout<<"queue: ";
        while(!st.isEmpty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;


    return 0;
}