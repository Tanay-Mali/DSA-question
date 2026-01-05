#include<iostream>
#include<vector>
using namespace std;

//Q704. Binary Search
//Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1. You must write an algorithm with O(log n) runtime complexity.

//Solve on self but logic was learn from video of Apna College
int binarysearch(vector<int> &nums, int target){
    int n = nums.size();
    int str=0;
    int end=n-1;
    while(str<=end){
        int mid=str+(end-str)/2;
        if(nums[mid] == target){
            return mid;
        }
        (target<nums[mid])?end=mid-1:str=mid+1;
    }
    return -1;
}

int main(){
    vector<int> nums={1,0,3,5,9,12};
    int target=9;
    cout<<binarysearch(nums,target);
    return 0;
}