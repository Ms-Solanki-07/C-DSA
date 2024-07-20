#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    unordered_map<int, string> record;

    record.insert(make_pair(2, "hello"));
    record[4] = "world";
    record[1] = "ms";

    for(auto pair: record){
        cout<<"roll: "<<pair.first<<endl;
        cout<<"name: "<<pair.second<<endl;
    }

    return 0;
}