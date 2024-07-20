#include<iostream>
#include<vector>
using namespace std;

void subSequence(string &str, int i, string result, vector<string> &li){
    if(i==str.length()){
        li.push_back(result);
        return;
    }
    subSequence(str, i+1, result+str[i], li);
    subSequence(str, i+1, result, li);

}

int main () {
    vector<string> li;
    string x = "abc";
    subSequence(x, 0, "", li);

    for(int i=0; i<li.size(); i++){
        cout<<li[i]<<" ";
    }
    
    return 0;
}