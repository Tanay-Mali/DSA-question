#include<iostream>
#include<vector>
using namespace std;

//Q26. Remove Duplicates from Sorted Array
//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k. The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

//Solved on self with Time Complexity O(n);

int removeDuplicates(vector<int> &nums){
    int k=0;
    int curr=nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i] == curr){
            continue;
        }
        else{
            k++;
            curr=nums[i];
            nums[k]=curr;
        }
    }
    return k+1;
}

int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums)<<endl;
}