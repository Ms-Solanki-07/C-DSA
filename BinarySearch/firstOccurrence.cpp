#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> &input, int target){   // time complexity - O(logN)
    int lo=0; 
    int hi=input.size()-1;
    int ans=-1;
    while(lo<=hi){
        int mid = lo+((hi-lo)/2);
        if(input[mid]==target){
            ans=mid;
            hi=mid-1;
        } else if(input[mid]>target){
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }
    return ans;
}

int main (){
    
    int n, target;
    cout<<"size of vector";
    cin>>n;
    vector<int> input;


    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        input.push_back(x);
    }

    cout<<"enter number:";
    cin>>target;
    cout<<firstOccurence(input, target);

    return 0;
}