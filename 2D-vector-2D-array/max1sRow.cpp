// given a boolean 2d array, where each row a sorted, find the row with the maximam number of 1s

#include<iostream>
#include<vector>
using namespace std;

int leftMostOneRow(vector<vector<int>> &v){
    int leftMostOne = -1;
    int maxOnesRow = -1;
    int j = v[0].size()-1;

    // finding liftmost one in 0th row
    while(j>=0 && v[0][j] ==1){
        leftMostOne = j;
        maxOnesRow = 0;
        j--;
    }

    // check in rest of the rows if we can find a one left to the leftMostOne
    for(int i=1; i<v.size(); i++){
        while(j>=0 && v[i][j] == 1){
            leftMostOne = j;
            j--;
            maxOnesRow = i;
        }
    }
    return maxOnesRow;
}

int maximumOnesRow(vector<vector<int>> &v){
    int maxOnes=INT16_MIN;
    int maxOnesRow = -1;
    int columns = v[0].size();
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){

            if(v[i][j]==1){
                int numberOfOnes = columns - j;
                if(numberOfOnes > maxOnes){
                    maxOnes = numberOfOnes;
                    maxOnesRow = i;
                }
            break;
            }
        }
    }
    return maxOnesRow;

}

int main () {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    // int res = maximumOnesRow(v);
    int res = leftMostOneRow(v);
    cout<<"row:"<<res<<endl;

    return 0;
}