#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int hitrogram(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    int ans = INT_MIN;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && arr[i] < arr[st.top()]){
            int ele = arr[st.top()];
            st.pop();
            int nse = i;
            int pse = st.empty()? -1 : st.top();
            ans = max(ans, ele*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int ele = arr[st.top()];
        st.pop();
        int nse = n;
        int pse = st.empty()? -1 : st.top();
        ans = max(ans, ele*(nse-pse-1));    
    }
    
    return ans;
}

int main(){
    int n;
    cout<<"size of vector:";
    cin>>n;
    vector<int> v;
    cout<<"vector element:";
    int c;
    for(int i=0; i<n; i++){
        cin>>c;
        v.push_back(c);
    }

    cout<<"area of max rectangle:"<<hitrogram(v)<<endl;

    return 0;
}