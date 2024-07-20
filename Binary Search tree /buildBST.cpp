#include<iostream>
#include<queue>
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

Node* insertintoBST(Node* &root, int data){
    if(root == NULL){
        Node* root = new Node(data);
        return root;
    }

    if(root->data > data){
        root->left = insertintoBST(root->left, data);
    }

    if(root->data < data){
        root->right = insertintoBST(root->right, data);
    }
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

void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data != -1){
        root = insertintoBST(root, data);
        cin>>data;
    }
}

int main() {

    Node* root = NULL;

    cout<<"Enter the data for create BST: "<<endl;
    takeInput(root);

    cout<<"Printing tree: "<<endl;
    levelOrderTraversal(root);

    return 0;
}
