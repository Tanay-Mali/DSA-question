#include<iostream>
#include<vector>
using namespace std;

//Q 27. Remove Element
//The question is to remove all occurrences of the number val from array nums and return the no.of element in nums which are not equal to val (i.e. k). And also change the array nums in-place such that it's first k element should be those element which are not equal to val. The element after that are not matter we can ignore them.

//Date:03-02-2026; Time:- 10:00am
//Solved: Accepted with time complexity O(N) runtime 3ms and space complexity O(N).
//Solution: 
//This is the easiest solution that i can write that's why it is with space O(N). first i made a vector ans to store the elementnot equal to val and a variable k to count those no.of element. and then just travel the given array form the ans array at then end change nums with ans array and return k.
//I try to think with manipulating the nums array using the function .erase but some of its variation gives TLE and some are not logically correct according to me. so i will try to find the correct solution either by my self of from video solution.

int removeElement(vector<int>& nums, int val) {
    int n=nums.size();
    vector<int> ans(n,0);
    int k=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=val){
            ans[k]=nums[i];
            k++;
        }
    }
    nums=ans;
    return k;
}

int main(){
    vector<int> nums={3,2,2,3};
    int val=3;
    int ans=removeElement(nums,val);
    for(int digit : nums){
        cout<<nums<<" ";
    }
}