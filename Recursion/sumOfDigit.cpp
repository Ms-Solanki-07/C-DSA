// given an integer, find out the sum of its digits using recursion

#include<iostream>
using namespace std;

int sum(int n){
    if(n>=0 and n<=9){
        return n;
    }
    return sum(n/10) + (n%10);
}

int main () {

    int n;
    cin>>n;

    cout<<"sum of digit : "<<sum(n);
    return 0;
}