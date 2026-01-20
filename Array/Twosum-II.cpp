#include<iostream>
#include<vector>
using namespace std;

//Q167. Two Sum II - Input Array Is Sorted
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length. Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.

//Date:20-01-2026 Time:10:30pm;
//Solution:Accepted with Time complexiety O(N) runtime 0ms and Space COmplexiety O(1);
//It is kind of easy solution if you already know the two pointer method or solved the question Container with most water(leetcode Q11).
//The Approach is first find sum of first and last element by pointing them with two pointers(str,end). The solution will exist and it is only one pair.
//So if the target is greater than sum of first and last element then we will change one element out of it and that is starting element (or increament str) because array is sorted in increasing order if sum of first and last is less than target we will increament str to increase the sum to reach the target ans in similar way if target is less that that sum we will decrease end pointer because we are decreasing the largest number in that pair.

vector<int> twoSum(vector<int>& numbers, int target) {
        int str=0;
        int end=numbers.size()-1;
        // vector<int> ans(2,0);
        while(str<end){
            if(numbers[str]+numbers[end]==target){
                return {str+1,end+1};
                break;
            }
            (numbers[str]+numbers[end]>target)?end--:str++;
        }
        return {str+1,end+1};
    }

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> ans=twoSum(nums,target);
    cout<<ans[0]<<"  "<<ans[1]<<endl;
}