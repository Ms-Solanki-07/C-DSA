// given a matrix "a" of dimension n*m and 2 coordinates (l1, r1) and (l2, r2). 
// return the um of the rectangle from (l1, r1) to (l2, r2). 

// third method
// prefix sum over columns and rows both


#include<iostream>
#include<vector>
using namespace std;

int rectangleSum(vector<vector<int>> &matrix, int l1, int r1, int l2, int r2){
    int sum=0;

    // prefix sum array row-wise
    for(int i=0; i<matrix.size(); i++){
        for(int j=1; j<matrix[i].size(); j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }

    // prefix sum array colums-wise
    for(int i=1; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            matrix[i][j]+=matrix[i-1][j];
        }
    }

    int topSum=0, leftSum=0, topLeftSum=0;
    if(l1!=0) topSum = matrix[l1-1][r2];
    if(r1!=0) leftSum = matrix[l2][r1-1];
    if(l1!=0 && r1!=0) topLeftSum = matrix[l1-1][r1-1];

    sum = matrix[l2][r2] - topSum - leftSum + topLeftSum;
    
    return sum;
}

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

    int sum = rectangleSum(matrix, l1, r1, l2, r2);
    cout<<"Sum: "<<sum;
   
    return 0;
}