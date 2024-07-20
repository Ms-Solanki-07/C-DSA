#include<iostream>
using namespace std;

int main () {

    int arr[] = {2,9 };

    int *ptr = &arr[0];

    cout<<ptr<<" "<<*ptr<<endl;
    
    cout<<(*ptr)++<<" "<<ptr<<endl;  //increment the value at this address by one 

    cout<<arr[0]<<" "<<arr[1]<<endl;


    return 0;
}