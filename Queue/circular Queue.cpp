#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class circularQueue{
    public:
    int front;
    int rear;
    int size;
    vector<int> v;
    
    circularQueue(int c){
        front = 0;
        rear = c-1;
        size = 0;
        v.resize(c);
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
    bool isFull() {
        return size == v.size();
    }
    
    void push(int x){
        if(isFull()){
            cout<<"circular queue is full"<<endl;
        } else {
            rear = (rear+1) % v.size();
            v[rear] = x;
            size++;
        }
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"queue is already empty"<<endl;
            return;
        }
        
        front = (front+1)%v.size();
        size--;
    }
    
    int getFront(){
        if(isEmpty()) return -1;
        
        return v[front];
    }
    
    
};



int main() {
    circularQueue cq(5);
    cq.push(8);
    cq.push(6);
    cq.push(5);
    cq.push(7);
    cq.push(9);
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.push(11);    

    
    
        cout<<"queue: ";
        while(!cq.isEmpty()){
            cout<<cq.getFront()<<" ";
            cq.pop();
        }
        cout<<endl;


    return 0;
}