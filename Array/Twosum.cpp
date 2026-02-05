#include<iostream>
#include<vector>
#include<unordered_map>
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


//Date:-05-02-2026
//Solution-2; Time complexity O(N) run time 3ms space complexity O(N). The solution i watch on youtube and learn how to solve hashing questions.
//This solution is with hashing means using maps or sets
//Here we use unordered_map starting with a single loop where we will store the number as key and its index as value in the map 
//The idea is we need two numbers sum upto target, So let assume the current indexed number is first number and we know the target, so subtracting first number from target will give the second required number.
//We are storing numbers in map also so we will try to find the second number in the map if that exist then we got both numbers if not then we will store that current number in map.
//This is unordered_map where accessing any key will take O(1) time and in worst case which is rare it will be O(N). and this is better that normal or multi_map. because they are in based like trees so the accessing time for them is O(log(N)).


vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapping;
        int first,sec;
        for(int i=0;i<nums.size();i++){
            first=nums[i];
            sec=target-first;
            if(mapping.find(sec)!=mapping.end()){
                return {i,mapping[sec]};
            }
            mapping[first]=i;
        }
        return{0,0};
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
