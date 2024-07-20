#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class doublyLinkedList{
    public:
    Node* head;
    Node* tail;
    
    doublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
};

int main(){
    Node* newNode = new Node(5);
    
    doublyLinkedList dll;
    dll.head = newNode;
    dll.tail = newNode;
    
    cout<<dll.head->val<<endl;
    
    return 0;
}


    