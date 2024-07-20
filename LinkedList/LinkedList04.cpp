// print linkedList in reverse order

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

class LinkedList{
    public:
    Node *head;
    
    LinkedList(){
        head = NULL;
    }
    
    void insertAtTail(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    
    void display() {
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
   
    
};


void reversePrint(Node* head){
    if(head == NULL){
        return;
    }
    
    reversePrint(head->next);
    cout<<head->val<<" ";
}

Node* reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = temp;
    }
    return prev;  // newHead
}

Node* reverseLLbyRecursion(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* newHead = reverseLLbyRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}


Node* reverseKNode(Node* &head, int k){
    Node* prev = NULL;
    Node* curr = head;
    
    int counter = 0;
    while(curr != NULL && counter<k){
        Node* next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
        counter++;
    }
    
    if(curr != NULL){
        Node* newHead = reverseKNode(curr, k);
        head->next = newHead;
    }
    
    return prev;
}

int main(){

    LinkedList ll;
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(7);
    ll.insertAtTail(4);
    ll.insertAtTail(9);
    ll.insertAtTail(0);
    ll.display();
    //ll.head = reverseLL(ll.head);
    //ll.display();
    //ll.head = reverseLL(ll.head);  //reverse of reversed linkedList
    //ll.display();
    
    //ll.head = reverseLLbyRecursion(ll.head);
    // ll.display();
    
    ll.head = reverseKNode(ll.head, 2);
    ll.display();
    
    
    
    return 0;
}