#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int rear;
    int size;
    vector<int> v;
    
    public: 
    Queue(){
        front = rear = -1;
        size = 0;
    }
    
    bool isEmpty(){
        return front == -1;
    }
    
    int getSize(){
        return size;
    }
    
    void enqueue(int val){
        if(front == -1){
            front++;
            rear++;
            v.push_back(val);
            size++;
            return;
        } else {
            rear++;
            v.push_back(val);
            size++;
            return;
        }
    }
    
    void dequeue(){
        if(front == -1){
            cout<<"Queue is already empyt"<<endl;
            return;
        } 
        if(front == rear){
            front = -1;
            rear = -1;
            size--;
            v.clear();
        } else {
            front++;
            size--;
        }
    }
    
    int getFront(){
         return v[front];
    }
};

void display(Queue qu){
    cout<<"Queue: ";
    while(!qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    } cout<<endl;
}

int main(){

    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(34);
    q.enqueue(67);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(667);
    

       
    display(q);
    cout<<q.isEmpty()<<endl;
    cout<<q.getSize()<<endl;
    
    return 0;
}