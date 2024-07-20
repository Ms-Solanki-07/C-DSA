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

class circularLinkedList {
    public:
    Node* head;
    
    circularLinkedList(){
        head = NULL;
    }
    
    
    void display(){
        Node* temp = head;
        do{
            cout<<temp->val<<"->";
            temp = temp->next;
        } while (temp != head);
        cout<<endl;
        return;
    }
    
    void printCircular(){
        Node* temp = head;
        for(int i=0; i<15; i++){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<endl; 
    }
    
    void insertAtStart(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode;
            newNode->next = head; //circularLinkedList
            return;
        }
        
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
        return;
    }
    
    int size(){
        int count = 0;
        Node* temp = head;
        do{
            temp = temp->next;
            count++;
        } while(temp != head);
        
        return count;
    }
    
    void insertAtPosition (int val, int k){
        if(k>size()){
            cout<<"value of k is more than size of linkedlist"<<endl;
            return;
        }
        if(k==1){
            insertAtStart(val);
            return;
        }
        if(k==size()){
            insertAtEnd(val);
            return;
        }
        
        Node* newNode = new Node(val);
        int count = 1;
        Node* temp = head;
        while(count<(k-1)){
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
    
    void deleteAtStart(){
        Node* temp = head;
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        free(temp);    
        return;
    }
    
    void deleteAtEnd(){
        Node* tail = head;
            while(tail->next->next != head){
                tail = tail->next;
            }
            Node* temp = tail->next;
            tail->next = head;
            free(temp);
            return;

    }
    
    void deleteAtPositioin(int k){
        if(k>size()){
            cout<<"value of k is more than size of linkedlist"<<endl;
            return;
        }
        if(k==1){
            deleteAtStart();        
            return;
        }
        if(k==size()){
            deleteAtEnd();
            return;
        }
        
        int count = 1;
        Node* temp = head;
        while(count < (k-1)){
            temp = temp->next;
            count++;
        }
        temp->next = temp->next->next;
        return;
    }
    
    
    void updateAtPosition(int newVal, int k){
        if(k>size()){
            cout<<"value of k is more than size of linkedlist"<<endl;
            return;
        }
        if(k==1){
            head->val = newVal;
            return;
        }
        if(k==size()){
            Node* tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            tail->val = newVal;
            return;
        }
        int count = 1;
        Node* temp = head;
        while(count < k){
            temp = temp->next;
            count++;
        }
        temp->val = newVal;
        return;
    }
};


int main () {

    circularLinkedList ll;
    
    /*ll.insertAtStart(3);
    ll.insertAtStart(2);
    ll.insertAtStart(1);
    ll.display();
    ll.insertAtEnd(4);
    ll.display();
    ll.printCircular();*/
    
    ll.insertAtEnd(1);
    ll.insertAtEnd(3);
    ll.insertAtEnd(7);
    ll.insertAtEnd(4);
    ll.display();
    //ll.insertAtPosition(6, 3);
    //ll.display();

    //ll.deleteAtStart();
    //ll.deleteAtEnd();
    //ll.deleteAtPositioin(3);
    ll.updateAtPosition(34,2);
    ll.display();
    ll.printCircular();
    
    
    
return 0;
}