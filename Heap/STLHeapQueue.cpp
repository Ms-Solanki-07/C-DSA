#include<iostream>
#include<queue>
using namespace std;

int main(){

    //max heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(7);

    cout<<"top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"top: "<<pq.top()<<endl;
    cout<<"size: "<<pq.size()<<endl;

    if(!pq.empty()){
        cout<<"heap is NOt empty"<<endl;
    } else {
        cout<<"heap is empty"<<endl;
    }


    //min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(9);
    minHeap.push(7);

    cout<<"top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"top: "<<minHeap.top()<<endl;
    cout<<"size: "<<minHeap.size()<<endl;

    if(!minHeap.empty()){
        cout<<"heap is NOt empty"<<endl;
    } else {
        cout<<"heap is empty"<<endl;
    }


    
    return 0;
}
