#include<iostream>
#include<vector>
using namespace std;

//Q 54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.

//Solved: Accepted with time complexity O(N*M) runtime 0ms and space complexity O(N*M);


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> ans;
    int srow=0,scol=0,erow=n-1,ecol=m-1;

    while(srow<=erow && scol<=ecol){
        //top
        for(int j=scol;j<=ecol;j++){
            ans.push_back(matrix[srow][j]);
        }

        //right
        for(int i=srow+1;i<=erow;i++){
            ans.push_back(matrix[i][ecol]);
        }

        //bottom
        for(int j=ecol-1;j>=scol;j--){
            if(srow==erow) break;
            ans.push_back(matrix[erow][j]);
        }

        //left
        for(int i=erow-1;i>srow;i--){
            if(scol==ecol) break;
            ans.push_back(matrix[i][scol]);
        }

        srow++;erow--;scol++;ecol--;
    }
    
    return ans;
    
}