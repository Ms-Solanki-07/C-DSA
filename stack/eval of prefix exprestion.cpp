#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

int cal(int v1, int v2, char op){
    if(op=='^') return pow(v1, v2);
    else if(op=='*') return v1*v2;
    else if(op=='+') return v1+v2;
    else if(op=='/') return v1/v2;
    else if(op=='-') return v1-v2;
    else if(op=='%') return v1%v2;
}

int eval(string &str){
    stack<int> st;
    for(int i=str.size()-1; i>=0; i--){
        char curr = str[i];
        if(isdigit(curr)){
            st.push(curr-'0');
        } else {
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(cal(v1, v2,curr));
        }
    }
    return st.top();
    
} 

int main() {
    string str = "/-235"; 
    cout<<eval(str)<<endl;

    return 0;
}