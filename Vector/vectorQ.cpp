// Given Q queries, check if the given number is present in the aaray or not
// NOTE- value of all the element in the array is less than 10 to the power 5


#include<iostream>
#include<vector>
using namespace std;


int main() {
    int n;

    cout<<"Enter the size of Array : ";
    cin>>n;

    cout<<"Enter the element of array : "<<endl;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    const int N = 1e5 + 10;  // 10 to the power 5
    vector<int> freq(N, 0);  //N-size, 0 se initialize
    for(int i=0; i<n; i++){
        freq[v[i]]++;
    }

    cout<<"Enter the Number of quries : ";
    int q;
    cin>>q;

    cout<<"Enter the quries : ";
    while(q--){
        int queryelement;
        cin>>queryelement;
        cout<<freq[queryelement]<<endl;
    }


    return 0;

}