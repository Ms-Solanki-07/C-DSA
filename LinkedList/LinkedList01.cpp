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

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAthead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void insertAtPosition(Node* &head, int val, int pos){
    if(pos == 0){
        insertAthead(head, val);
        return;
    }
    
    Node* newNode = new Node(val);
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos != pos-1){
        temp = temp->next;
        curr_pos++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void updationAtPosition(Node* &head, int val, int pos){
    Node* temp = head;
    int currPos = 0;
    while(currPos != pos){
        temp = temp->next;
        currPos++;
    }
    temp->val = val;
}

void deletAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deletAtTail(Node* &head){
    Node* secLast = head;
    while(secLast->next->next != NULL){
        secLast = secLast->next;
    }
    Node* temp = secLast->next;
    secLast->next = NULL;
    free(temp);
}

void deletAtPosition(Node* &head, int pos){
    if(pos == 0){
        deletAtHead(head);
        return;
    }
    
    Node* prev = head;
    int currPos = 0;
    while(currPos != pos-1){
        prev = prev->next;
        currPos++;
    }
    Node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);

}

int main(){
    Node* head = NULL;    
    insertAthead(head, 5);
    display(head);
    insertAthead(head, 4);
    display(head);
    insertAtTail(head, 6);
    display(head);
    insertAtPosition(head, 8, 1);
    display(head);
    updationAtPosition(head, 9, 1);
    display(head);
    
    //deletAtHead(head);
    //display(head);
    //deletAtTail(head);
    //display(head);
    deletAtPosition(head, 1);
    display(head);
    
    return 0;
}