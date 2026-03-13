#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//238. Product of Array Except Self
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

//Date:-31-01-2026, Time:-5:15pm;
//Solved: Accepted with Time Complexity O(N) Runtime 3ms and Space complexity O(N);
//This is the first question where i learn the concept of prefix and suffix and also i use this to solve the question Running sum of array(leetcode Q1480).So i watch the video solution on youtube for it.But it was a month ago now so i write this solution then check it in video whether it is correct or not
//Solution:
//The main point of this question is do not use division operator without that we need prefix and suffix. So if we observe the array the product of array except self is basically product of elements before that index (Which we called prefix) and after that index (which we called suffix). we created two array prefix and suffix, running loop two times on given array to get prefix and suffix of each element then multiply the corresponding prefix suffix to get the final answer array.

vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> prefix(n,1);
    vector<int> suffix(n,1);
    vector<int> ans(n,1);
    //Calculating prefix
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*nums[i-1];
    }  
    //Calculating suffix
    for(int j=n-2;j>=0;j--){
        suffix[j]=suffix[j+1]*nums[j+1];
    }
    //Calculating final Ans;
    for(int i=0;i<n;i++){
        ans[i]=prefix[i]*suffix[i];
    }
    return ans;
}

//This solution is with improve space complexity which i was not remember properly.
//What we do is store the prefix in ans array and then run a loop in backward direction calculating suffix and multiplying it with current index which is prefix simultaneously hence it was done using 1 array.

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;i++){
       ans[i] = ans[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=n-2;i>=0;i--){
       suffix*=nums[i+1];
       ans[i]*=suffix;
    }
    return ans;
}

int main(){
    vector<int> nums={1,2,3,4};
    vector<int> ans=productExceptSelf(nums);
    for(int i=0;i<nums.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}