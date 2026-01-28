#include<iostream>
#include<vector>
using namespace std;

//Q34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

//Date:27-01-2026, Time:-8:00pm
//Solved:Accepted with Time Complexity O() runtime 2ms and space complexity O(1);
//Solution:This is may be bad level of brute force approch but I just want to submit a valid answer so i do it.
//First I try with finding the target with binary search if found then check neighbouring elements are also equal to target if true then store those index in array ans and return that ans array. 
//But the problem is if i found target and before that index same target is present 4-5 index before also so how can i find that particular index And we don't know how much they are. 
//To solve this I run two different loops of binary search for finding the first and last occurence of that element. The important thing is array is sorted so target element will be present in sequence. And the different thing which help us to find the first and last element is : the element before the first target element is different and in simillar way the element after the last target element is also different. So i use this two condition to find the first and last occurence of target element
//then store these element in ans array and return that array 
//Remaining is the some cases of given array size is 0 or 1 or 2. So I handled them initially to avoid the address overflow error in running the loop.


vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        if(nums.size()==1){
            if(nums[0]==target)
                {return {0,0};}
            else{
                return{-1,-1};
            }
        }
        if(nums.size()==2){
            if(nums[0]==target && nums[1]==target) return {0,1};
            else if(nums[0]==target) return{0,0};
            else if(nums[1]==target) return {1,1};
            else return{-1,-1};
        }
        int str1=0;
        int end1=nums.size()-1;
        int mid1;
        int str2=0;
        int end2=nums.size()-1;
        int mid2;
        vector<int> ans(2,0);
        while(str1<=end1){
            mid1=str1+(end1-str1)/2;
            if(mid1==0) break;
            if(mid1!=0){
                if(nums[mid1]==target && nums[mid1-1]!=target){
                break;
                }
                if((nums[mid1]==target && nums[mid1-1]==target) || (nums[mid1]>target)){
                    end1=mid1-1;
                } else if(nums[mid1]<target){
                    str1=mid1+1;
                }
            }
            
        }
        
        while(str2<=end2){
            mid2=str2+(end2-str2)/2;
            
            if(mid2!=nums.size()-1){
                if(nums[mid2]==target && nums[mid2+1]!=target){
                break;
                }
                if((nums[mid2]==target && nums[mid2+1]==target) || (nums[mid2]<target)){
                    str2=mid2+1;
                } else if(nums[mid2]>target){
                    end2=mid2-1;
                }
            }
            if(mid2==nums.size()-1) break;
        }
        if(nums[mid1]!=target) mid1=-1;
        if(nums[mid2]!=target) mid2=-1;
        ans={mid1,mid2};
        return ans;
    }