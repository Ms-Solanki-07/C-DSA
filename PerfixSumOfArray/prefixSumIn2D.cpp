// given a matrix "a" of dimension n*m and 2 coordinates (l1, r1) and (l2, r2). 
// return the um of the rectangle from (l1, r1) to (l2, r2). 

#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> matrix(n, vector<int> (m));

    cout<<"enter element : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    int l1,r1, l2,r2;
    cout<<"enter the l1,r1 : ";
    cin>>l1>>r1;
    cout<<"enter the l2,r2: ";
    cin>>l2>>r2;

    int sum=0;
    for(int i=l1-1; i<l2; i++){
        for(int j=r1-1; j<r2; j++){
            sum+=matrix[i][j];
        }
    }

    cout<<"Sum:"<<sum;

    return 0;
}