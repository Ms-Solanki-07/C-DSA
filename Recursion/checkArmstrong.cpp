// check armstrong number or not
// armstrong number - an armstrong numbner is a number if the sum of every digit in that 
// number raised to the power of total digits in that number is equal to the number.

#include<iostream>
using namespace std;

int power(int p, int q){
    if(q==0) return 1;
    if(q%2==0){
        int result = power(p, q/2);
        return result*result;
    } else {
        int result = power(p, (q-1)/2);
        return p*result*result;
    }
}

int checkArmstrong(int n, int d){
    if(n==0) return 0;
    return power(n%10, d) + checkArmstrong(n/10.0, d);
}

int main () {
    int n;
    cin>>n;

    int noOfDigits = 0;
    int temp = n;
    while(temp>0){
        temp = temp/10;
        noOfDigits++;
    }

    if(checkArmstrong(n, noOfDigits)==n){
        cout<<"Yes"<<endl;
    } else {
        cout<<"NO"<<endl;
    } 
   return 0; 
}