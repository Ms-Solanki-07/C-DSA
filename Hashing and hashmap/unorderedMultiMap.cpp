#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    unordered_multimap<string,int> record;

    record.insert(make_pair("ms", 6348));
    record.insert(make_pair("hello", 4548));
    record.insert(make_pair("ms", 66548));
    record.insert(make_pair("hllo", 45478));
    record.insert(make_pair("ms3", 648));
    //record["hey"] = 4523;  NOT allowed in multimap

    for(auto pair: record){
        cout<<"Name: "<<pair.first<<endl;
        cout<<"phoneNo: "<<pair.second<<endl;
    }
    
    
    return 0;
}