#include<iostream>
#include<stack>
using namespace std;

bool isValid(string str){
    stack<char> st;
    for(int i=0; i<str.size(); i++){
        char curr = str[i];
        if(curr=='(' || curr=='{' || curr=='['){
            st.push(curr);
        } else {
            if(curr == ')' && !st.empty() && st.top() == '('){
                st.pop();            
            } else if(curr == '}' && !st.empty() && st.top() == '{'){
                st.pop();            
            } else if(curr == ']' && !st.empty() && st.top() == '['){
                st.pop();            
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str = "{()[]}()(])";
    cout<<isValid(str);

    return 0;
}