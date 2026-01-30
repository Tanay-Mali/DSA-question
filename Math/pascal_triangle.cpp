#include<iostream>
#include<vector>
using namespace std;

//Q118. Pascal's Triangle
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

//Date:-30-01-2026, Time:5:00pm
//Solved: Accepted With Time Complexity O(numrows²) Runtime 0ms and space complexity O(numrows²)
//Solution is easier than i thought just the problem before this is how can i generate an array where the array inside it is of increasing size. But then I remember about vector because they can increase capacity dynamically while we can add new element by push back so use this to solve it.

//Solution: I start with initiating a 2d vector with its inner vector of size 0, I don't know about that we can initiate a vector with zero size but i try and it works. Then observing to real pascal's triangle i get that the first and last element is 1 and remaining are sum of the element above them and previous to the the above element.
//For example: If we are on element a[i][j] then it will be sum of a[i-1][j-1] and a[i-1][j] so here the a[i-1][j-1] is element before the element above the current element and a[i-1][j] is element above current element. Yes it may be confusing while explaining it in words but i will try to make a video to explain these things.
//And to track the size of current row like horizontally i use the variable size which was updated once a row is completed. 


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows,vector<int> (0,0));
    int size=1;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<size;j++){
            if(j==0 || j==size-1){
                ans[i].push_back(1);
            }
            else{
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        size++;
    }
    return ans;
}

int main(){
    int n=5;
    vector<vector<int>> ans=generate(n);
    int size=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<size;j++){
            cout<<ans[i][j];
        }
        size++;
        cout<<endl;
    }
    return 0;
}