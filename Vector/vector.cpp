#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> v;

    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(6);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    cout<<endl;

    v.resize(8);
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.pop_back();
    cout<<"Size : "<<v.size()<<endl;
    cout<<"Capacity : "<<v.capacity()<<endl;


    return 0;
}
