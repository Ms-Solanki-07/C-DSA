#include<iostream>
#include<queue>
using namespace std;
// stack using queue
// pop efficient

class stack{
    queue<int> qe;
    
    public:
    stack() {}
    
    void push(int x) { //enqueue time: O(n)
        queue<int> temp;
        while(!qe.empty()){
            temp.push(qe.front());
            qe.pop();
        }
        qe.push(x);
        while(!temp.empty()){
            qe.push(temp.front());
            temp.pop();
        }
    }
    
    void pop(){  // dequeue  time O(1);
        if(qe.empty()) return;
        qe.pop();
    }
    
    int top(){    // dequeue  time O(1);
        if(qe.empty()) return 0;
        return qe.front();
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
    
    //st.pop();
    
    
        cout<<"queue: ";
        while(!st.isEmpty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;


    return 0;
}