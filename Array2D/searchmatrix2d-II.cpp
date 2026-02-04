#include<iostream>
#include<vector>
using namespace std;

//Q 240. Search a 2D Matrix II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// 1. Integers in each row are sorted in ascending from left to right.
// 2. Integers in each column are sorted in ascending from top to bottom.

//Date:-04-02-2026; Time:-12:15pm
//Solved and accepted all three solution where first two solutions are written by me and the third solution i saw on youtube. All are different in sense of logic and time complexity.

//Solution-1:
//This is Solution with Time complexity O(N*log(M)).
//For this we know all rows are sorted in asceding order so we can apply binary search on rows; but the problem is with column, columns are also sorted so in each row the last element may not be less than the first element of next row.
//Now we know that rows are sorted so i simply apply binary on each row. Which was accepted with runtime 97ms Time complexity O(N*log(M)) and space complexity O(1).
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        int str=0;
        int end=m-1;
        while(str<=end){
            int mid=str+(end-str)/2;
            if(matrix[i][mid]==target) return true;
            (matrix[i][mid]<target)?str=mid+1:end=mid-1;
        }
    }
    return false;
}


//Solution-2:
//This is Solution with Time complexity O(M∗Log(N)+N∗Log(M)).
//For this I think each row and column are sorted, means we can apply binary on row and column. So I write this solution by travelling along diagonal and implement binary on the row and column in which I am standing
//But this result runtime 181ms Time complexity O(M∗Log(N)+N∗Log(M)) and Space Complexity O(1);

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int i=0,j=0;
    int str,end;
    int mid;
    for(int i=0,j=0;i<n && j<m;i++,j++){
        str=0;
        end=m-1;
        while(str<=end){
            mid=str+(end-str)/2;
            if(matrix[i][mid]==target) return true;
            (matrix[i][mid]<target)?str=mid+1:end=mid-1;
        }
        str=0,end=n-1;
        while(str<=end){
            mid=str+(end-str)/2;
            if(matrix[mid][j]==target) return true;
            (matrix[mid][j]<target)?str=mid+1:end=mid-1;
        }
    }
    
    return false;
    
}

//Solution-3;
//This is Solution with Time complexity O(M∗Log(N)+N∗Log(M)). And this is optimal solution that i saw on youtube.
//The idea is to remove the column or row accordingly.
//The approch is like first we took a corner from secondary diagonal (here we took the upper right corener), then compare it with the target. Since the column is sorted in ascending order vertically and in decresing order horizontally. it the target is greater than the corner element then it can't be in that row in which the corner, and similarly if the target is smaller than the corner element then it can't be in that column.
//Now according to this just remove the row if target is greater and remove the column if target is smaller.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(),m=matrix[0].size();
    int row=0,col=m-1;
    while(col>=0 && row<n){
        if(matrix[row][col]==target){
            return true;
        }else if(matrix[row][col]>target){
            col--;
        }else{
            row++;
        }
    }
    return false;
    
}

int main(){
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout<<searchMatrix(matrix,5);
    return 0;
}
