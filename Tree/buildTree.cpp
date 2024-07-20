#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<root->data<<": "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<root->data<<": "<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    if(!root){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  //seprator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){  //purana level complete hone pr enter
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } 
        else {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorderWithoutRecursion(Node* root){
    stack<Node*> s;
    Node* curr = root;

    while(!s.empty() || curr != NULL){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
       
        curr = curr->right;
        
    }
}

void preorderWithoutRecursion(Node* root){
    stack<Node*> s;
    Node* curr = root;

    while(!s.empty() || curr != NULL){

        while(curr != NULL){
            cout<<curr->data<<" ";
            if(curr->right) {
                s.push(curr->right);
            }
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
    }
    
}

void postorderWithoutRecursion(Node* root){
    if (root == NULL) return;

    stack<Node*> s;
    Node* lastVisited = NULL;
    Node* curr = root;

    while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        } else {
            Node* peekNode = s.top();
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                cout << peekNode->data << " ";
                lastVisited = s.top();
                s.pop();
            }
        }
    }
}

void buildTreeformlevelorder(Node* &root){
    queue<Node*> q;
    cout<<"enter data for root: ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"enter the data for left "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;
        
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;
        
        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }

    }
}

int main() {
    Node* root = NULL;

    //creating tree
    root = buildTree(root);
    // buildTreeformlevelorder(root);

    //level order
    // 1 3 7 -1 -1 11 -1 -1 5 9 -1 -1 -1  
    // cout<<endl<<"levelOrder: "<<endl;                                                    
    // levelOrderTraversal(root);
    // cout<<endl;

    /*
    cout<<"inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
*/ 
    
    // cout<<endl<<"inorder: ";
    // inorderWithoutRecursion(root);

    // cout<<endl<<"preorder: ";
    // preorderWithoutRecursion(root);

    cout<<endl<<"postorder: ";
    postorderWithoutRecursion(root);

    return 0;
}