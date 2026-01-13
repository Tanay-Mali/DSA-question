#include<iostream>
#include<vector>
using namespace std;


//Q977. Squares of a Sorted Array
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

//Date:-13-01-2026 Time:-7:00 pm
//Solved and accepted with runtime 562ms 
//Solution:
//What I think is the Given array is already sorted in incresing order and we have to square the each number. The problem is only negative number which are at initial postion/index in array but have sqaure which may be placed at the last part of array
//So first thing is the number which are positive are already arrange we just have to squre them so I run i loop in reverse direction by squaring each number and use the condition if number is negative we will square it and starting from that same index we will compare it with next index and swap if it is greater than next index 
//Flow of program
//Square each number starting from last index if number is negative sort or place it in its proper position by swaping with next index


vector<int> sortedSquares(vector<int>& nums) {
    int n=nums.size();  
    vector<int> ans(n,0);

    for(int i=n-1;i>=0;i--){
        ans[i]=nums[i]*nums[i];
        if(nums[i]<0){//check if the number is negative them place it on proper position by swapping
            for(int j=i;j<n-1;j++){
            if(ans[j]>ans[j+1]){
                swap(ans[j],ans[j+1]);
            }
        }
        }
        

    }
    return ans;
}

int main(){
    vector<int> nums={-4,-1,0,3,10};
    vector<int> ans=sortedSquares(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;;

    }
    return 0;
}