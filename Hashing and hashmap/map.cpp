#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string, int> directory;
    directory["wnimesh"]  = 62342;
    directory["hello"] = 5673;
    directory["wow"] = 4563;
    directory["wow"] = 3462;

    for(auto ele: directory){
        cout<<"name: "<<ele.first<<endl;
        cout<<"roll: "<<ele.second<<endl;
    }
    cout<<endl;

   // directory.insert(make_pair("wow", 56343));

    for(auto ele: directory){
        cout<<"name: "<<ele.first<<endl;
        cout<<"roll: "<<ele.second<<endl;
    }
    cout<<endl;

    return 0;
}