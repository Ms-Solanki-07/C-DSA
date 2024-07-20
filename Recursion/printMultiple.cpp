// given a number num and a value k. print k multiple of num.

#include<iostream>
using namespace std;

void printMultiple(int num, int k){
    if(k==0){
        return;
    }
    printMultiple(num, k-1);
    cout<<(num*k)<<" ";
}

int main() {
    int n=9;
    int k=5;
    printMultiple(n,k);
}