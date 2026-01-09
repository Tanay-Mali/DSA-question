#include<iostream>
#include<vector>
using namespace std;

// 1480. Running Sum of 1d Array(Too easy)
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.

//Time Complexity = O(n), runtime=0ms
//I figured out that prefix can be use to optimize it but regret that i see the topic in the section and get that hint prefix is used 
//So regret to see the hint to such a easy question


vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int prefix=0;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=nums[i]+prefix;
            prefix=ans[i];
        }
        return ans;
    }

int main(){
    vector<int> nums={1,2,3,4};
    vector<int> ans=runningSum(nums);
    for(int i=0;i<nums.size();i++){
        cout<<ans[i]<<endl;
    }
}