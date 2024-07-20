#include<iostream>
#include<stack>

using namespace std;

string eval(string &pre){
    reverse(pre.begin(), pre.end());
    stack<string> st;
    for(int i=0; i<pre.size(); i++){
        if(isdigit(pre[i])){
            st.push(to_string(pre[i]-'0'));
        } else {
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            
            string newExp = v1+v2+pre[i];
            st.push(newExp);
        }
    }
    return st.top();
}

int main()
{
    string pre = "-+32*52";
    string post = eval(pre);
    cout<<post<<endl;

    return 0;
}