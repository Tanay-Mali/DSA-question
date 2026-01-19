#include<iostream>
#include<vector>
using namespace std;


//Q867. Transpose Matrix
// Given a 2D integer array matrix, return the transpose of matrix. The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

//Date:19-01-2026 Time: 10:15pm
//Solution(Solved on self)
//It is really easy to solve than i think but i solved with Time complexity O(N^2) and since we have to travel whole matrix so the time will be O(N^2) ans runtime 0ms with Space complexiety O(N*M)
//The approach is just set first Row of answer array to first element of each row of given array And same for remaining array


vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    vector<vector<int>> ans(matrix[0].size(),vector<int> (matrix.size(),0));
    for(int i=0;i<matrix[0].size();i++){
        for(int j=0;j<matrix.size();j++){
            ans[i][j]=matrix[j][i];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans=transpose(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}