// given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

#include<iostream>
#include<vector>
using namespace std;

void transposeOfMatrix(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            swap(v[i][j], v[j][i]);
        }
    }
    return;
}

void reverseRowOfTransposeMatrix(vector<vector<int>> &v){
    for(int i=0; i<v.size(); i++){
        int leftptr = 0;
        int rightptr = v[i].size()-1;

        while(leftptr<rightptr){
            swap(v[i][leftptr], v[i][rightptr]);
            leftptr++;
            rightptr--; 
        }

    }

    return;
}

int main () {
    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int> (n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }

    transposeOfMatrix(v);
    reverseRowOfTransposeMatrix(v);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}