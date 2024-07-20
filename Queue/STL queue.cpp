#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(4);  //enqueue
    q.push(6);
    q.push(8);
    q.push(10);
    q.push(12);
    q.pop();  //dequeue

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }    
    cout<<endl;

    return 0;
}