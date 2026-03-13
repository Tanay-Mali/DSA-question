#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Q 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){

            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1;
            int k=n-1;

            while(j<k){

                int sum=nums[i]+nums[j]+nums[k];

                if(sum<0) j++;
                else if(sum>0) k--;
                else {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--; 

                    while(j<k && nums[j]==nums[j-1]){
                    j++;
                    }
                    
                }
                
            }
        }
        return ans;
    }