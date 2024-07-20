#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(curr);
}

void insertAtIdx(stack<int> &st, int x, int idx){
    if(idx > st.size()-1){
        cout<<"index is NOT exist"<<endl;
        return;
    }
    if(st.size() == idx){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtIdx(st, x, idx);
    st.push(curr);
}

void removeFromBottom(stack<int> &st){
    if(st.size() == 1){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    removeFromBottom(st);
    st.push(curr);
}

void removeFromIdx(stack<int> &st, int idx){
    if(idx > st.size()-1){
        cout<<"index is NOT exist"<<endl;
        return;
    }
    if(st.size() == idx+1){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    removeFromIdx(st, idx);
    st.push(curr);
}

void reverse(stack<int> &st){
    stack<int> t1, t2;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }
    while(!t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    while(!t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}

void reverseByRecursion(stack<int> &st){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    reverseByRecursion(st);
    insertAtBottom(st, curr);
    return;
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    
    //insertAtBottom(s, 56);
    //insertAtIdx(s, 45, 2);
    //removeFromBottom(s);
    //removeFromIdx(s, 9);
    //reverse(s);        //O(n)
    reverseByRecursion(s);   //O(n^2)
    
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        cout<<curr<<endl;
    }
    
    
    return 0;
}