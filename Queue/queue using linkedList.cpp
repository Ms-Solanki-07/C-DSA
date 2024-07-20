#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;
    
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void enqueue(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void dequeue() {
        if(head == NULL){
            cout<<"queue is already empty"<<endl;        
            return;
        }
        if(head == tail){
            head = tail = NULL;
            size--;
            return;
        }
        
        Node* oldHead = head;
        head = head->next;
        
        oldHead->next = NULL;
        free(oldHead);
        size--;
        
    }
    
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return head == NULL;
    }
    
    int getFront(){
        if(head == NULL){
            return -1;
        }
        return head->val;
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
       
    display(q);
    cout<<q.isEmpty()<<endl;
    cout<<q.getSize()<<endl;
    
    return 0;
}