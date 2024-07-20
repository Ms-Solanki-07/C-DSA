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
    
   
    void deleteAlternate() {
        Node *curr = head;
        while(curr != NULL && curr->next != NULL){
            Node *temp = curr->next;
            curr->next = curr->next->next;;
            curr = curr->next;   
        }
    
    }
    
};


int main(){

    LinkedList ll;
    ll.insertAtTail(5);
    ll.insertAtTail(9);
    ll.insertAtTail(6);
    ll.insertAtTail(4);
    ll.insertAtTail(7);
    ll.insertAtTail(3);
    ll.display();
    ll.deleteAlternate();
    ll.display();
    
    
    return 0;
}