#include<iostream>
using namespace std;

string removeA(string &s, int idx, int n){
    if(idx==n){
        return "";
    }
    string curr = "";
    curr += s[idx];
    return ((s[idx]=='a') ? "" : curr) + removeA(s, idx+1, n);
}

int main () {
    string x = "abcax";
    cout<<removeA(x, 0, 5);
    return 0;
}