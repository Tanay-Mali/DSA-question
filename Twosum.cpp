#include<iostream>
#include<vector>
using namespace std;

//1. Two Sum
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

//This is Brute force approach with time complexity O(n^2) on date 8-1-2026 Soon i will try to optimize this solution
//The approach is no brainer currently for me because this approach was first come to my mind but i try to find the optimal solution 
//This solution was accepted with 43ms runtime which is good because First aim is to find a acceptable solution then optimize it 


vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    ans[0]=i;
                    ans[1]=j;
                    return ans;
                }
            }
        }
        return ans;
    }

int main(){
    vector<int> nums={2,7,11,15};
    int target = 9;
    vector<int> ans=twoSum(nums,target);
    for(int i=0;i<2;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
