#include<iostream>
#include<vector>
using namespace std;

// void sortByParity(vector<int> &v){
//     int leftptr = 0;
//     int rightptr = v.size()-1;
    
//     while(leftptr<rightptr){
//         if(v[leftptr]%2 == 1 && v[rightptr]%2 == 0){
//             swap(v[leftptr], v[rightptr]);
//             leftptr++;
//             rightptr--;
//         }

//         if(v[leftptr]%2 == 0){
//             leftptr++;
//         }
//         if(v[rightptr]%2 == 1){
//             rightptr--;
//         }
//     }
//     return;
// }

int main (){
    int n;
    cout<<"Enter the size : ";
    cin>>n;

    vector<int> v(n);
    cout<<"Enter the element of vector : ";
    for(int i=0; i<n; i++){
        // int ele;
        // cin>>ele;
        // v.push_back(ele);
        cin>>v[i];
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // sortByParity(v);

    int leftptr = 0;
    int rightptr = v.size()-1;
    
    while(leftptr<rightptr){
        if(v[leftptr]%2 == 1 && v[rightptr]%2 == 0){
            swap(v[leftptr], v[rightptr]);
            leftptr++;
            rightptr--;
        }

        if(v[leftptr]%2 == 0){
            leftptr++;
        }
        if(v[rightptr]%2 == 1){
            rightptr--;
        }
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;



    return 0;


}