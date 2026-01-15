#include<iostream>
#include<vector>
using namespace std;

//Q852. Peak Index in a Mountain Array
// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

//Date:-15-01-2026, Time:-3:25pm, 
//Solved : The first approach came to my mind is brute force approach but then i try to optimize it with binary search and successfully got the logic which use binary search and is optimize solution but I failed to write that solution in C++ language 
//So finally I saw video on Apna college then I understand that my logic was correct but the code i was writing is in wrong sequence 
//After that day, today i again solved it with same approach without any help with time complexity O(log(n)) because it use the binary search and runtime 0ms 

//Solution:
//Solution logic is easy to understand, such that in binary search we just have to identify the search space is it right or left 
//By comparing the mid value with is neighbour value we can identify that where the peak index can be found. Like if the value after mid is greater and before mid is smaller then the peak index must lies in right half of the array and similar logic for left side, And if mid value is greater the either side value then it is peak index we will return that value.
//And since it is int return type function it must return a  value at the end of function so i return value -1 which denote to the error like no peak index was there

int peakIndex(vector<int>& nums){
    int n=nums.size();
    int str=0;
    int end=n-1;

    while(str<end){
        int mid=str+(end-str)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
        }else{
            (nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1])?str=mid:end=mid;
        }
    }
    return -1;

}

int main(){
    vector<int> arr={0,10,5,2};
    int ans=peakIndex(arr);
    cout<<ans<<endl;

    return 0;
}