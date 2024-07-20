/*
there are N stones, numbered 1,2....N. for each i (1<=1<=N), the height of stone i is hi, there is a frog who is
initialy on stone 1. he will repeat the following action some number of times to reach stone N.

if the frog is currently on stone i, jump to stone i+1 OR stone i+2. here a cost of |hi-hj| is incurred, 
where j is the stone to land on.

find the minimum possible total cost incurred before the frog reaches stone N.

*/

#include<iostream>
using namespace std;
int minimumCost(int *h, int n, int i){
    if(i==n-1) return 0;
    if(i==n-2) return minimumCost(h, n, i+1) + abs(h[i]-h[i+1]);

    return min(minimumCost(h, n, i+1) + abs(h[i]-h[i+1]), minimumCost(h, n, i+2) + abs(h[i]-h[i+2]));
}

int main() {
    int hightStone[] = {10,20,20,30};
    int n = 4;
    cout<<minimumCost(hightStone, n, 0);
}