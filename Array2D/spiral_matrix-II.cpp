#include<iostream>
#include<vector>
using namespace std;

//Q 59. Spiral Matrix II
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

//Solved: Accepted with Time Complexity O(N²) runtime 0ms and Space complexity O(N²)

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n,vector<int> (n,0));
    int val=1;
    int srow=0,erow=n-1,scol=0,ecol=n-1;

    while(srow<=erow){
        //top border
        for(int j=scol;j<=ecol;j++){
            ans[srow][j]=val;
            val++;
        }

        //right border
        for(int i=srow+1;i<=erow;i++){
            ans[i][ecol]=val;
            val++;
        }

        //bottom border
        for(int j=ecol-1;j>=scol;j--){
            if(srow==erow) break;
            ans[erow][j]=val;
            val++;
        }

        //left border
        for(int i=erow-1;i>srow;i--){
            if(scol==ecol) break;
            ans[i][scol]=val++;
        }

        srow++,erow--;scol++;ecol--;
    }

    return ans;
    
}