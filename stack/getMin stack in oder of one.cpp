#define ll long long int

#include<iostream>
#include<stack>
using namespace std;

class minStack{
    stack<ll> st;
    ll min;
    
    public:
    void push(int val){    //O(1)
        if(st.empty()){
            min = val;
            st.push(val);
        } else {
            st.push(val-min);
            if(min > val){
                min = val;
            }
        }
    }
    
    void pop(){          //O(1)
        if(!st.empty()){
            if(st.top() >= 0){
                st.pop();
            } else {
                min = min - st.top();
                st.pop();
            }
        }
    }
    
    int top(){        //O(1)
        if(st.size() == 1){
            return st.top();
        } else {
            if(st.top() < 0){
                return min;
            } else {
                return min+st.top();
            }
        }
    }
    
    int getMin(){     //O(1)
        return min;    
    } 
    
};

int main(){
    minStack s;
    s.push(-5);
    s.push(4);
    s.push(-2);
    s.push(5);
    s.push(2);
    
    //s.pop();
    //s.pop();
    //s.pop();
    //s.pop();
    cout<<"top:"<<s.top()<<endl;
    cout<<"min: "<<s.getMin()<<endl;
    

    return 0;
}