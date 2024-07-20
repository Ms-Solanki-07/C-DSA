// HCF- higtest common factor
// Euclid's algorithm- if we subtract/division a smaller number from a larger number, 
// (we can reduce the larger no) but the GCD(HCF) will not change.

#include<iostream>
using  namespace std;  

int HCF(int a,int b){
    if(b>a) return HCF(b, a);  //swap
    if(b==0) return a;
    return HCF(b, a%b);
}
int main() {
    cout<<HCF(20,45);
    return 0;
}


