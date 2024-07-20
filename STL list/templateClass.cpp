#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T val;
    Node* next;
    
    Node(T data){
        val = data;
        next = NULL;
    }
};

int main(){
    Node<int> node1(5);
    Node<int>* node2 = new Node<int> (10);
    Node<char> node3('M');
    
    cout<<node1.val<<endl;
    cout<<node2->val<<endl;
    cout<<node3.val<<endl;
    
    return 0;
}