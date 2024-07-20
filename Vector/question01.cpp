// here, given is a sorted array in increaing order 
// output- sorted array in square form

#include<iostream>
#include<vector>
using namespace std;

void sortedSquaredArray(vector<int> &v){
    vector<int> ans;

    int leftptr=0;
    int rightptr=v.size()-1;

    while(leftptr<=rightptr){
        if(abs(v[leftptr])<abs(v[rightptr])){
            ans.push_back(v[rightptr]*v[rightptr]);
            rightptr--;
        } else {
            ans.push_back(v[leftptr]*v[leftptr]);
            leftptr++;
        }
    }

    // reverse(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int main() {
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;

    vector<int> v(n);

    cout<<"Enter the element of vector with increasing order  : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<"element of vector : ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    sortedSquaredArray(v);

    return 0;
}