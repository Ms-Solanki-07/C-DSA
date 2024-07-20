#include<iostream>
#include<unordered_map>
using namespace std;

bool checkNotOnetoMany(string s1, string s2){
    unordered_map<char, char> m;

    for(int i=0; i<s1.length(); i++){
        if(m.find(s1[i]) != m.end()){
            if(m[s1[i]] != s2[i]){
                return false;
            }
        }
        else {
            m[s1[i]] = s2[i];
        }
    }
    return true;
}

bool checkIso(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    //check one to many s1->s2
    bool s1s2 = checkNotOnetoMany(s1,s2);

    //check one to many s2->s1
    bool s2s1 = checkNotOnetoMany(s2,s1);

    return s1s2 && s2s1;
}

int main() {

    string s1,s2;
    cin>>s1>>s2;

    cout<<(checkIso(s1,s2)?"Yes isomorphic": "NOT isomorphic");

    return 0;
}