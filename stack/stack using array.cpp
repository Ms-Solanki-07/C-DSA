#include<iostream>
using namespace std;

class stack {
    int capacity;
    int top;
    int* arr;
    
    public:
    stack(int c){
        capacity = c;
        top = -1;
        arr = new int[c];
    }
    
    int size(){
        return top+1;
    }
    
    bool isFull(){
        return top == capacity-1;
    }
    
    bool isEmpty(){
        return top == -1;
    }
    
    void push(int val){
        if(isFull()){
            cout<<"Condition overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
        return;
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"Condition underflow"<<endl;
            return;
        }
        top = top-1;
        return;
    }
    
    void peak(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return;
        }
        cout<<arr[top]<<endl;
        return;    
    }
    
};

int main(){
    stack s(5);
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(2);
    s.push(1);
    s.pop();
    s.peak();

    return 0;
}