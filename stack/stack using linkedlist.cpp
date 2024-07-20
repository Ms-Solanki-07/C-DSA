#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    
    Node(int data){
        val = data;
        next = NULL;
    }
};

class stack {
    Node* head;
    int capacity;
    int currSize;
    
    public:
    stack(int data){
        head = NULL;
        capacity = data;
        currSize = 0;
    }
    
    bool isEmpty(){
        return head == NULL;
    }
    
    int size(){
        return currSize;
    }
    
    bool isFull(){
        return currSize == capacity;
    }
    
    void push(int data){
        if(isFull()){
            cout<<"Condition overflow"<<endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        currSize++;
        return;
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"condition underflow"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        currSize--;
        return;
    }
    
    void peak(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        cout<<head->val<<endl;
        return;
    }

};

int main () {
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.peak();

return 0;
}