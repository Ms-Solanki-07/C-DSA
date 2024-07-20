#include<iostream>
#include<vector>

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




bool checkEqual(Node* head1, Node* head2){
    while(head1 != NULL && head2 != NULL){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return (head1 == NULL && head2 == NULL);
}

int getLength(Node* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }
    return length;
}

Node* moveKstep(Node* head, int k){
    while(k--){
        head = head->next;
    }
    return head;
}

Node* getIntersection(Node* head1, Node* head2){
    
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    Node* ptr1;
    Node* ptr2;

    if(l1>l2){
        int k = l1-l2;
        ptr1 = moveKstep(head1, k);
        ptr2 = head2;
    } else {
        int k = l2-l1;
        Node* ptr2 = moveKstep(head2, k);    
        Node* ptr1 = head1; 
    }
    
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->next == ptr2->next){
            return ptr1->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return NULL;
}

void deleteKthNodeFromEnd(Node* &head, int k){
    Node* ptr1 = head;
    Node* ptr2 = head;
    int count = k;
    
    while(count--){
        ptr2 = ptr2->next;
    }

    if(ptr2 == NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    
    while(ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);

}

Node* mergedLinkedList(Node* &head1, Node* &head2){
    Node* dummyNode = new Node(-1);
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyNode;

    while(ptr1 && ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    
    if(ptr1){
        ptr3->next = ptr1;
    } else {
        ptr3->next = ptr2;
    }
    
    return dummyNode->next;
}


Node* mergedKlinkedList(vector<Node* > lists){
    if(lists.size() == 0){
        return NULL;
    }
    
    while(lists.size() > 1){
        Node* mergedHead = mergedLinkedList(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

Node* findMiddleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
    
}

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    if(!head){
        NULL;
    }
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    
    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast);
    
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;    
    }
    slow->next = NULL;
}




bool isPelindrome(Node* head){
    
    //find middle
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //break the linkedlist form middle
    Node* curr = slow->next;
    slow->next = NULL;
    Node* prev = slow;
    
    //reverse the 2nd half of the linkedlist
    while(curr){
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    }
    
    //check equal is or not
    Node* head1 = head;
    Node* head2 = prev;
    while(head2){
        if(head1->val != head2->val){
            return false;
        }
        head1= head1->next;
        head2= head2->next;
    }
    return true;
}


Node* rotateByKtimes(Node* &head, int k){
    //find n- number of node
    //find tail
    
    int n = 0;
    Node* tail = head;
    
    while(tail->next){
        n++;
        tail= tail->next;
    }
    n++;
    
    k=k%n;
    if(k==0){
        return head;
    }
    
    tail->next = head;
    Node* temp = head;
    for(int i=1; i<n-k; i++){
        temp= temp->next;
    }
    Node* newHead = temp->next;
    temp->next = NULL;
    return newHead;

}


Node* oddEvenLinkedList(Node* &head){
    if(!head){
        return head;
    }
    
    Node* evenHead = head->next;
    Node* oddPtr = head;
    Node* evenPtr = head->next;
    
    while(evenPtr && evenPtr->next){
        oddPtr->next = oddPtr->next->next;
        evenPtr->next = evenPtr->next->next;
        oddPtr = oddPtr->next;
        evenPtr = evenPtr->next;
    }
    
    oddPtr->next = evenHead;
    return head;

}

Node* reoderLinkedList(Node* &head){
    if(!head){
        return head;
    }
    
    //find middle
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //seperate the linkedlist
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;
    
    //reverse the second half LinkedList
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    
    //merege
    Node* ptr1 = head;
    Node* ptr2 = prev;
    while(ptr1 != ptr2){
        Node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
    return head;
    
}    

Node* swapAdjecent(Node* &head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* secondNode = head->next;
    head->next = swapAdjecent(secondNode->next);
    secondNode->next = head;
    return secondNode;
}
 
int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.insertAtTail(7);    
    ll1.display();


    LinkedList ll2;
    ll2.insertAtTail(0);
    ll2.insertAtTail(1);
    ll2.insertAtTail(5);
    ll2.insertAtTail(7);
    ll2.insertAtTail(8);
 //   ll2.display();
    
    //cout<<checkEqual(ll1.head, ll2.head);
    
    
//    LinkedList ll2;
//   ll2.insertAtTail(4);
//    ll2.insertAtTail(6);
//    ll2.head->next->next = ll1.head->next->next->next;
//    ll2.display();
    
//    Node* intersection = getIntersection(ll1.head, ll2.head);
//    cout<<intersection->val;

        
    //deleteKthNodeFromEnd(ll1.head, 7);
    //ll1.display();
    
  //  LinkedList ll3;
  //  ll3.head = mergedLinkedList(ll1.head, ll2.head);
  //  ll3.display();
    
    
  /*  LinkedList ll3;
    ll3.insertAtTail(1);
    ll3.insertAtTail(6);
    ll3.insertAtTail(10);
    ll3.insertAtTail(12);
    ll3.insertAtTail(16);
    ll3.display();
    
    vector<Node* > lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    
    LinkedList mergedLL;
    mergedLL.head = mergedKlinkedList(lists);
    mergedLL.display();

  */
  
 //   Node* middleNode = findMiddleNode(ll1.head);
 //   cout<<"MIDDLE NODE : "<<middleNode->val<<endl;  
  /* ll1.head->next->next->next->next->next->next = ll1.head->next->next;
   //ll1.display(); cycle linkelist me display nhi krte
   cout<<detectCycle(ll1.head)<<endl;
   removeCycle(ll1.head);
   cout<<detectCycle(ll1.head)<<endl; 
    ll1.display();
  */
  
 // cout<<isPelindrome(ll1.head);  
   
 //  ll1.head = rotateByKtimes(ll1.head, 2);
 //  ll1.display(); 
   
   
   
   //ll1.head = oddEvenLinkedList(ll1.head);
   //ll1.display();
   
   //ll1.head = reoderLinkedList(ll1.head);
   //ll1.display();
   
   
   ll1.head = swapAdjecent(ll1.head);
   ll1.display();
    
    return 0;
}