#include<iostream>
#include<stack>
using namespace std;

stack<int> copyStack(stack<int> input){
    stack<int> temp;
    while(!input.empty()){
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    
    stack<int> result;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void copyStackByRecursion(stack<int> &input, stack<int> &result){
    if(input.empty()){
        return;
    }
    int curr = input.top();
    input.pop();
    copyStackByRecursion(input, result);
    result.push(curr);
    return;
}

void printStack(stack<int> s){
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        cout<<curr<<endl;
    }
}

int main () {
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    
    stack<int> res = copyStack(s);
    
    cout<<"using temp:"<<endl;
    printStack(res);
    
    stack<int> r;
    copyStackByRecursion(s, r);
    cout<<"using recursion:"<<endl;
    printStack(r);
       
    return 0;
}