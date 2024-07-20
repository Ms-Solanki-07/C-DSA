#include<iostream>
using namespace std;

int main () {

    int arr[] = {2,3};

    int *ptr = &arr[0];

    cout<<ptr<<" "<<*ptr<<endl;
    
    cout<<*ptr++<<" "<<ptr<<endl;  //increment the address by one unit of size of integer

    cout<<arr[0]<<" "<<arr[1]<<endl;


    return 0;
}