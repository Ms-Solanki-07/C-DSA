// write a program to check whether a given number is palindrome or not.

#include<iostream>
using namespace std;

bool palindrome(int num, int *temp){
    if(num >= 0 and num <=9){
        return (num == (*temp)%10);
    }
    bool result = (palindrome(num/10, temp) and (num%10) == ((*temp)%10));
    (*temp)/=10;
    return result;
}
int main () {
    int num = 12621;
    int temp = num;
    cout<<palindrome(num, &temp);

    return 0;
}