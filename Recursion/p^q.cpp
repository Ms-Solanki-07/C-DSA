#include<iostream>
using namespace std;

int power(int p, int q){
    if(q==0){
        return 1;
    }
    return p*power(p, q-1);
}
int main () {
    int p,q;
    cin>>p>>q;
    cout<<"p^q: "<<power(p, q);
    return 0;
}