#include<iostream>
#include<vector>
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
    
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"-";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    int size(){   
        Node* temp = head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }
    
    void insertAtStart(int val){
        Node* newNode = new Node(val);
            
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }    
                    
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        
        if(tail == NULL){  //linkedlist are empty
            head = newNode;
            tail = newNode;
            return;
        }
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }
    
    void insertAtPosition(int val, int k){
        Node* newNode = new Node(val);
        
        if(k==1){
            insertAtStart(val);
            return;
        }
        
        if(k>size()){
            insertAtEnd(val);
            return;
        }
        //here we assume that k is less then equal size of linkedlist
        
        Node* temp = head;
        int count = 1;
        while(count<(k-1)){
            temp = temp->next;
            count++;
        } 
        
        //here temp pointing to k-1 position
        newNode->next = temp->next;
        temp->next = newNode;
        
        newNode->prev = temp;
        newNode->next->prev = newNode;
        return;
        
    }
    
    
    void deleteAtStart(){
        if(head==NULL){
            return;
        }
        
        Node* temp = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    
    void deleteAtEnd(){
        if(head == NULL){
            return;
        }
        
        Node* temp = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
        } else {
            tail->next = NULL;
        }
        free(temp);
        return;
    }
    
    void deleteAtPosition(int k){
        if(head == NULL){
            return;
        }
        if(k==1){
            deleteAtStart();
            return;
        } 
        if(k>=size()){
            deleteAtEnd();
            return;
        }
        
        Node* temp = head;
        int count = 1;
        while(count<k){
            temp= temp->next;
            count++;
        }
        // temp pointing to kth position
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }

        
};


void reverseDll(Node* &head, Node* &tail){
        Node* currPtr = head;
        while(currPtr){
            Node* nextPtr = currPtr->next;
            currPtr->next = currPtr->prev;
            currPtr->prev = nextPtr;
            currPtr = nextPtr;
        }
        
        Node* temp = head;
        head = tail;
        tail = temp;
        return;
}

bool isPelindrome(Node* head, Node* tail){
    if(head->next == NULL){
        return true;
    }
    while(head != tail && tail != head->prev){
        if(head->val != tail->val){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

void deleteSameNeighbourNode(Node* &head, Node* &tail){
    // RIGHT TO LEFT
    if(head->next==NULL){
        return;
    }
    
    Node* currNode = tail->prev; // second last Node
    while(currNode != head){
        Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        if(prevNode->val == nextNode->val){
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
    return;
}

bool isCriticalPoint(Node* currNode){
    if(currNode->next->val < currNode->val && currNode->prev->val < currNode->val){
        return true; // local maxima
    }
    if(currNode->next->val > currNode->val && currNode->prev->val > currNode->val){
        return true; // local minima
    }
    
   return false; 
}

vector<int> distanceBetweenCriticalPoint(Node* &head, Node* &tail){
    vector<int> ans(2, INT_MAX);
    int firstCp = -1; 
    int lastCp = -1;
    
    Node* currNode = tail->prev;
    if(currNode==NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }
    
    int currPos = 0;
    while(currNode->prev != NULL){
        if(isCriticalPoint(currNode)){
            if(firstCp == -1){
                firstCp = lastCp = currPos; 
            } else {
                ans[0] = min(ans[0], currPos-lastCp); //min distance
                ans[1] = currPos - firstCp; //max distance
                lastCp = currPos;
            }
        }
        currPos++;
        currNode = currNode->prev;
    }
    
    if(ans[0] == INT_MAX){
        ans[0] = ans[1] = -1;
    }
    return ans;
}

vector<int> targetSum(Node* head, Node* tail, int x){
    vector<int> ans(2, -1);
    ans[0] = -1;
    ans[1] = -1;
    
    while(head != tail){
        int sum = head->val + tail->val;
        if(sum == x){
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }
        if(sum>x){
            tail = tail->prev;
        }
        if(sum<x){
            head = head->next;
        }
    }
    return ans;
    
}


int main () {

    doublyLinkedList dll;
    //dll.insertAtStart(2);
    //dll.insertAtStart(3);
    //dll.insertAtStart(2);
    //dll.insertAtStart(1);
    //dll.display();
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(3);
    dll.display();
    //cout<<"size :"<<dll.size()<<endl;
    //dll.insertAtPosition(8,5);
    //dll.display();
    
    //dll.deleteAtStart();
    //dll.deleteAtEnd();
    
    //dll.deleteAtPosition(7);
    //dll.display();
    
    
    //reverseDll(dll.head, dll.tail);
    //dll.display();
    
    //cout<<isPelindrome(dll.head, dll.tail)<<endl;
    
    //deleteSameNeighbourNode(dll.head, dll.tail);
    //dll.display();
 
    //vector<int> ans = distanceBetweenCriticalPoint(dll.head, dll.tail);
    //cout<<"min: "<<ans[0]<<" "<<"Max: "<<ans[1]<<endl;

    vector<int> ans = targetSum(dll.head, dll.tail, 9);
    cout<<ans[0]<<" "<<ans[1]<<endl;

return 0;
}